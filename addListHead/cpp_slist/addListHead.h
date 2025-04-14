#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <map>
#include <optional>
#include <list>
#include <variant>
#include <memory>

// for base defi
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
    // static slist<T1> sCons(const T1 &p1, const slist<T1> &p2) {
    //     // return slist<T1> ( _sCons ( p1, p2 ) );
    // }

    // 浅拷贝版本的sCons
    static slist<T1> sCons(const T1 &p1, const slist<T1> &p2) {
        // struct timespec start, temp1, temp2, end;
        // timespec_get(&start, TIME_UTC);
        bool res = std::holds_alternative<_sNil>(p2.value_);
        // timespec_get(&temp1, TIME_UTC);
        if(res) {
            // 如果p2是nil，直接创建新节点指向p2的共享指针
            // std::cout << " nil" << std::endl;
            return slist<T1>(_sCons(p1, std::make_shared<slist<T1>>(p2)));
        } else {
            // 对于非nil情况
            const _sCons& p2_cons = std::get<_sCons>(p2.value_);
            // timespec_get(&temp2, TIME_UTC);
            std::shared_ptr nil_ptr = std::make_shared<slist<T1>>(_sNil());
            std::shared_ptr first_ptr = std::make_shared<slist<T1>>(_sCons(p2_cons.p1_, nil_ptr));
            _sCons& first = std::get<_sCons>((*first_ptr).value_);
            first.p2_ = p2_cons.p2_;
            // timespec_get(&end, TIME_UTC);

            // long long elapsed1 = (temp1.tv_sec - start.tv_sec) * 1000000000LL + (temp1.tv_nsec - start.tv_nsec);
            // long long elapsed2 = (temp2.tv_sec - temp1.tv_sec) * 1000000000LL + (temp2.tv_nsec - temp1.tv_nsec);
            // long long elapsed3 = (end.tv_sec - temp2.tv_sec) * 1000000000LL + (end.tv_nsec - temp2.tv_nsec);
            // std::cout << elapsed1 << " " << elapsed2 << " " << elapsed3 << std::endl;

            return slist<T1>(_sCons(p1, first_ptr));
        }
    }

    // static slist<T1> sCons(const T1 &p1, slist<T1>&& p2) {
    //     // 如果是临时对象（右值），直接移动
    //     return slist<T1>(_sCons(p1, std::make_shared<slist<T1>>(std::move(p2))));
    // }


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



// template<typename T1>
// class slist {
//     struct _sNil {
//         bool operator<(const _sNil &) const { return false; }
//     };
//     struct _sCons {
//         T1 p1_;
//         std::shared_ptr<slist<T1>> p2_;

//         const T1 &p1() const { return p1_; }
//         slist<T1> p2() const { return *p2_; }

//         bool operator<(const _sCons &rhs) const {
//             return std::tie(p1_, *p2_) < std::tie(rhs.p1_, *rhs.p2_);
//         }
//     };

//     std::variant<_sNil, _sCons> value_;
//     slist(const std::variant<_sNil, _sCons> &value) : value_(value) {}

//   public:
//     slist() = default;

//     static slist<T1> sNil() {
//         return slist<T1> { _sNil {  } };
//     }
//     static slist<T1> sCons(const T1 &p1, const slist<T1> &p2) {
//         return slist<T1> { _sCons { p1, std::make_shared<slist<T1>>(p2) } };
//     }

//     bool is_sNil() const { return std::holds_alternative<_sNil>(value_); }
//     bool is_sCons() const { return std::holds_alternative<_sCons>(value_); }

//     const _sCons &as_sCons() const { return std::get<_sCons>(value_); }

//     bool operator<(const slist<T1> &rhs) const { return value_ < rhs.value_; }
// };


template<typename T1>
slist<T1> AddListHead(const T1 &arg1, const slist<T1> &arg2) {
    // AddListHead a xs = sCons a  xs
    auto a = arg1;
    auto xs = arg2;
    auto temp0 = slist<T1>::sCons(
        std::move(a),
        std::move(xs)
    );
    return temp0;
}