#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <map>
#include <optional>
#include <list>
#include <variant>
#include <memory>

template<typename T1>
class slist {
    struct _sNil {
        _sNil() {}
        _sNil(const _sNil& other){ }
        _sNil(_sNil&& other) noexcept{ }
        _sNil& operator=(const _sNil& other) { return *this; }
        _sNil& operator=(_sNil&& other) noexcept { return *this; }
        bool operator==(const _sNil &) const { return true; }
        bool operator<(const _sNil &) const { return false; }
        bool operator>(const _sNil &) const { return false; }
        bool operator<=(const _sNil &) const { return true; }
        bool operator>=(const _sNil &) const { return true; }
    };
    struct _sCons {
        T1 p1_;
        std::shared_ptr<slist<T1>> p2_;

        const T1 &p1() const { return p1_; }
        slist<T1> p2() const { return *p2_; }


        // 新增的构造函数，用于浅拷贝p2
        _sCons(const T1& p1, std::shared_ptr<slist<T1>> p2)
            :p1_(p1)
            ,p2_(std::move(p2))
        {}
        _sCons(const _sCons& other)
            :p1_(other.p1_)
            ,p2_(std::make_shared<slist<T1>>(*other.p2_))
        {}
        _sCons(_sCons&& other) noexcept 
            :p1_(std::move(other.p1_))
            ,p2_(std::move(other.p2_))
        { }

        _sCons& operator=(const _sCons& other){ 
            if(this != &other){ 
                p1_ = other.p1_; 
                p2_.reset();
                p2_ = std::make_shared<slist<T1>>(*other.p2_);
            } 
            return *this; 
        } 
        _sCons& operator=(_sCons&& other) noexcept {
            if(this != &other) {
                p1_ = std::move(other.p1_);
                p2_ = std::move(other.p2_);
            }
            return *this;
        }
        bool operator==(const _sCons &rhs) const {
            return (std::tie(p1_, *p2_) == std::tie(rhs.p1_, *rhs.p2_));
        }
        bool operator<(const _sCons &rhs) const {
            return (std::tie(p1_, *p2_) < std::tie(rhs.p1_, *rhs.p2_));
        }
        bool operator>(const _sCons &rhs) const {
            return (std::tie(p1_, *p2_) > std::tie(rhs.p1_, *rhs.p2_));
        }
        bool operator<=(const _sCons &rhs) const {
            return (std::tie(p1_, *p2_) <= std::tie(rhs.p1_, *rhs.p2_));
        }
        bool operator>=(const _sCons &rhs) const {
            return (std::tie(p1_, *p2_) >= std::tie(rhs.p1_, *rhs.p2_));
        }
    };

  public:

    std::variant<_sNil, _sCons> value_;

    //默认构造函数
    slist(){
        value_ = _sNil();
    }
    //value构造函数
    slist(std::variant<_sNil, _sCons> value) : value_(std::move(value)) {}
    //深拷贝构造函数
    slist(const slist<T1>& other) { 
        if(std::holds_alternative<_sNil>(other.value_)){ 
            const _sNil& other_node = std::get<_sNil>(other.value_); 
            value_ = other_node;
        } 
        if(std::holds_alternative<_sCons>(other.value_)){ 
            const _sCons& other_node = std::get<_sCons>(other.value_); 
            value_ = other_node;
        } 
    } 
    //移动构造函数
    slist(slist<T1>&& other){
        if(std::holds_alternative<_sNil>(other.value_)){ 
            _sNil& other_node = std::get<_sNil>(other.value_); 
            value_ = std::move(other_node);
        } 
        if(std::holds_alternative<_sCons>(other.value_)){ 
            _sCons& other_node = std::get<_sCons>(other.value_); 
            value_ = std::move(other_node);
        } 
    }

    static slist<T1> sNil() {
        return slist<T1> ( _sNil (  ) );
    }

    // 浅拷贝版本的sCons
    // static slist<T1> sCons(const T1 &p1, const slist<T1> &p2) {
    //     if(std::holds_alternative<_sNil>(p2.value_)) {
    //         // 如果p2是nil，直接创建新节点指向p2的共享指针
    //         return slist<T1>(_sCons(p1, std::make_shared<slist<T1>>(p2)));
    //     } else {
    //         // 对于非nil情况
    //         const _sCons& p2_cons = std::get<_sCons>(p2.value_);
    //         std::shared_ptr nil_ptr = std::make_shared<slist<T1>>(_sNil());
    //         std::shared_ptr first_ptr = std::make_shared<slist<T1>>(_sCons(p2_cons.p1_, nil_ptr));
    //         _sCons& first = std::get<_sCons>((*first_ptr).value_);
    //         first.p2_ = p2_cons.p2_;
    //         return slist<T1>(_sCons(p1, first_ptr));
    //     }
    // }
    static slist<T1> sCons(T1 p1, slist<T1> p2) {
        if(std::holds_alternative<_sNil>(p2.value_)) {
            // 如果p2是nil，直接创建新节点指向p2的共享指针
            return slist<T1>(_sCons(p1, std::make_shared<slist<T1>>(p2)));
        } else {
            // 对于非nil情况
            const _sCons& p2_cons = std::get<_sCons>(p2.value_);
            std::shared_ptr nil_ptr = std::make_shared<slist<T1>>(_sNil());
            std::shared_ptr first_ptr = std::make_shared<slist<T1>>(_sCons(p2_cons.p1_, nil_ptr));
            _sCons& first = std::get<_sCons>((*first_ptr).value_);
            first.p2_ = p2_cons.p2_;
            return slist<T1>(_sCons(p1, first_ptr));
        }
    }

    bool is_sNil() const { return std::holds_alternative<_sNil>(value_); }
    bool is_sCons() const { return std::holds_alternative<_sCons>(value_); }
    const _sCons &as_sCons() const { return std::get<_sCons>(value_); }
    slist<T1>& operator=(slist<T1>&& other) noexcept {
        if(this != &other){
            if(std::holds_alternative<_sNil>(other.value_)){
                _sNil& other_value = std::get<_sNil>(other.value_);
                value_ = std::move(other_value);
            }
            if(std::holds_alternative<_sCons>(other.value_)){
                _sCons& other_value = std::get<_sCons>(other.value_);
                value_ = std::move(other_value);
            }
        }
        return *this;
    }
    //拷贝赋值运算符
    slist<T1>& operator=(const slist<T1>& other){ 
        if(this != &other){ 
            if(std::holds_alternative<_sNil>(other.value_)){ 
                const _sNil& other_node = std::get<_sNil>(other.value_); 
                value_ = other.value_; 
            } 
            if(std::holds_alternative<_sCons>(other.value_)){ 
                const _sCons& other_node = std::get<_sCons>(other.value_); 
                value_ = other.value_; 
            } 
        } 
        return *this; 
    }

    bool operator==(const slist<T1> &rhs) const {
        if(value_.index() == rhs.value_.index()){
             return value_ == rhs.value_;
        }else{
            return false;
        }
    }

    bool operator<(const slist<T1> &rhs) const {
        if(value_ == rhs.value_) return false;
        return value_ < rhs.value_; 
    }

    bool operator>(const slist<T1> &rhs) const {
        if(value_ == rhs.value_) return false;
        return value_ > rhs.value_; 
    }

    bool operator<=(const slist<T1> &rhs) const {
        if(value_ == rhs.value_) return true;
        return value_ < rhs.value_; 
    }

    bool operator>=(const slist<T1> &rhs) const {
        if(value_ == rhs.value_) return true;
        return value_ > rhs.value_; 
    }

};

template<typename T1>
slist<T1> Insert(T1 arg1, slist<T1> arg2) {
    // Insert a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = arg1;
        auto temp0 = slist<T1>::sCons(
            std::move(a),
            slist<T1>::sNil()
        );
        return temp0;
    }

    // Insert a (sCons x xs) =(if a \<le> x then (sCons a (sCons x xs)) else (sCons x (Insert a xs)))
    auto a = std::move(arg1);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    slist<T1> temp0;
    if (a <= x) {
        auto temp1 = slist<T1>::sCons(
            std::move(x),
            std::move(xs)
        );
        auto temp2 = slist<T1>::sCons(
            std::move(a),
            std::move(temp1)
        );
        temp0 = std::move(temp2);
    } else {
        auto temp3 = slist<T1>::sCons(
            std::move(x),
            Insert(std::move(a), std::move(xs))
        );
        temp0 = std::move(temp3);
    }
    return temp0;
}

