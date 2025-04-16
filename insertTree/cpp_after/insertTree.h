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
class tree {
    struct _Tip {
        _Tip() {}
        _Tip(const _Tip& other){ }
        _Tip(_Tip&& other) noexcept{ }
        _Tip& operator=(const _Tip& other) { return *this; }
        _Tip& operator=(_Tip&& other) noexcept { return *this; }
        bool operator==(const _Tip &) const { return true; }
        bool operator<(const _Tip &) const { return false; }
        bool operator>(const _Tip &) const { return false; }
        bool operator<=(const _Tip &) const { return true; }
        bool operator>=(const _Tip &) const { return true; }
    };
    struct _Node {
        std::shared_ptr<tree<T1>> p1_;
        T1 p2_;
        std::shared_ptr<tree<T1>> p3_;

        tree<T1> p1() const { return *p1_; }
        const T1 &p2() const { return p2_; }
        tree<T1> p3() const { return *p3_; }


        _Node(std::shared_ptr<tree<T1>> p1, T1 p2, std::shared_ptr<tree<T1>> p3 )
            :p1_(std::move(p1))
            ,p2_(std::move(p2))
            ,p3_(std::move(p3))
        {}
        _Node(const _Node& other)
            :p1_(std::make_shared<tree<T1>>(*other.p1_))
            ,p2_(other.p2_)
            ,p3_(std::make_shared<tree<T1>>(*other.p3_))
        {}
        _Node(_Node&& other) noexcept 
            :p1_(std::move(other.p1_))
            ,p2_(std::move(other.p2_))
            ,p3_(std::move(other.p3_))
        { }

        _Node& operator=(const _Node& other){ 
            if(this != &other){ 
                p1_.reset();
                p1_ = std::make_shared<tree<T1>>(*other.p1_);
                p2_ = other.p2_; 
                p3_.reset();
                p3_ = std::make_shared<tree<T1>>(*other.p3_);
            } 
            return *this; 
        } 
        _Node& operator=(_Node&& other) noexcept {
            if(this != &other) {
                p1_ = std::move(other.p1_);
                p2_ = std::move(other.p2_);
                p3_ = std::move(other.p3_);
            }
            return *this;
        }
        bool operator==(const _Node &rhs) const {
            return (std::tie(*p1_, p2_, *p3_) == std::tie(*rhs.p1_, rhs.p2_, *rhs.p3_));
        }
        bool operator<(const _Node &rhs) const {
            return (std::tie(*p1_, p2_, *p3_) < std::tie(*rhs.p1_, rhs.p2_, *rhs.p3_));
        }
        bool operator>(const _Node &rhs) const {
            return (std::tie(*p1_, p2_, *p3_) > std::tie(*rhs.p1_, rhs.p2_, *rhs.p3_));
        }
        bool operator<=(const _Node &rhs) const {
            return (std::tie(*p1_, p2_, *p3_) <= std::tie(*rhs.p1_, rhs.p2_, *rhs.p3_));
        }
        bool operator>=(const _Node &rhs) const {
            return (std::tie(*p1_, p2_, *p3_) >= std::tie(*rhs.p1_, rhs.p2_, *rhs.p3_));
        }
    };

  public:

    std::variant<_Tip, _Node> value_;

    //默认构造函数
    tree(){
        value_ = _Tip();
    }
    //value构造函数
    tree(std::variant<_Tip, _Node> value) : value_(std::move(value)) {}
    //深拷贝构造函数
    tree(const tree<T1>& other) { 
        if(std::holds_alternative<_Tip>(other.value_)){ 
            // const _Tip& other_node = std::get<_Tip>(other.value_); 
            // value_ = other_node;
            value_ = std::get<_Tip>(other.value_);
        } 
        if(std::holds_alternative<_Node>(other.value_)){ 
            // const _Node& other_node = std::get<_Node>(other.value_); 
            // value_ = other_node;
            value_ = std::get<_Node>(other.value_);
        } 
    } 
    //移动构造函数
    tree(tree<T1>&& other){
        if(std::holds_alternative<_Tip>(other.value_)){ 
            // _Tip& other_node = std::get<_Tip>(other.value_); 
            // value_ = std::move(other_node);
            value_ = std::move(std::get<_Tip>(other.value_));
        } 
        if(std::holds_alternative<_Node>(other.value_)){ 
            // _Node& other_node = std::get<_Node>(other.value_); 
            // value_ = std::move(other_node);
            value_ = std::move(std::get<_Node>(other.value_));
        } 
    }

    static tree<T1> Tip() {
        return tree<T1> ( _Tip (  ) );
    }
    static tree<T1> Node(tree<T1> p1, T1 p2, tree<T1> p3) {
        return tree<T1>(_Node(            
            std::make_shared<tree<T1>>(std::move(p1))
            , std::move(p2)
            , std::make_shared<tree<T1>>(std::move(p3)) 
        ));
    }

    bool is_Tip() const { return std::holds_alternative<_Tip>(value_); }
    bool is_Node() const { return std::holds_alternative<_Node>(value_); }
    const _Node &as_Node() const { return std::get<_Node>(value_); }
    tree<T1>& operator=(tree<T1>&& other) noexcept {
        if(this != &other){
            if(std::holds_alternative<_Tip>(other.value_)){
                // _Tip& other_value = std::get<_Tip>(other.value_);
                // value_ = std::move(other_value);
                value_ = std::move(std::get<_Tip>(other.value_));
            }
            if(std::holds_alternative<_Node>(other.value_)){
                // _Node& other_value = std::get<_Node>(other.value_);
                // value_ = std::move(other_value);
                value_ = std::move(std::get<_Node>(other.value_));
            }
        }
        return *this;
    }
    //拷贝赋值运算符
    tree<T1>& operator=(const tree<T1>& other){ 
        if(this != &other){ 
            if(std::holds_alternative<_Tip>(other.value_)){ 
                // const _Tip& other_node = std::get<_Tip>(other.value_); 
                // value_ = other.value_; 
                value_ = std::get<_Tip>(other.value_);
            } 
            if(std::holds_alternative<_Node>(other.value_)){ 
                // const _Node& other_node = std::get<_Node>(other.value_); 
                // value_ = other.value_; 
                value_ = std::get<_Node>(other.value_);
            } 
        } 
        return *this; 
    }

    bool operator==(const tree<T1> &rhs) const {
        if(value_.index() == rhs.value_.index()){
             return value_ == rhs.value_;
        }else{
            return false;
        }
    }

    bool operator<(const tree<T1> &rhs) const {
        if(value_ == rhs.value_) return false;
        return value_ < rhs.value_; 
    }

    bool operator>(const tree<T1> &rhs) const {
        if(value_ == rhs.value_) return false;
        return value_ > rhs.value_; 
    }

    bool operator<=(const tree<T1> &rhs) const {
        if(value_ == rhs.value_) return true;
        return value_ < rhs.value_; 
    }

    bool operator>=(const tree<T1> &rhs) const {
        if(value_ == rhs.value_) return true;
        return value_ > rhs.value_; 
    }

};


template<typename T1>
tree<T1> inserttree(T1 arg1, tree<T1> arg2) {
    // inserttree a Tip= Node Tip a Tip
    if (arg2.is_Tip()) {
        auto a = std::move(arg1);
        auto temp0 = tree<T1>::Node(
            tree<T1>::Tip(),
            std::move(a),
            tree<T1>::Tip()
        );
        return temp0;
    }

    // inserttree a (Node left x right) = (if a\<le>x then (Node (inserttree a left) x right)  ...
    auto a = std::move(arg1);
    auto left = std::move(*arg2.as_Node().p1_);
    auto x = std::move(arg2.as_Node().p2_);
    auto right = std::move(*arg2.as_Node().p3_);
    tree<T1> temp0;
    if (a <= x) {
        auto temp1 = tree<T1>::Node(
            inserttree(std::move(a), std::move(left)),
            std::move(x),
            std::move(right)
        );
        temp0 = std::move(temp1);
    } else {
        auto temp2 = tree<T1>::Node(
            std::move(left),
            std::move(x),
            inserttree(std::move(a), std::move(right))
        );
        temp0 = std::move(temp2);
    }
    return temp0;
}

