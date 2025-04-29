#include "../../../AgenType/newType.h"



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

template<typename T1>
bool searchtree1(T1 arg1, tree<T1> arg2) {
    // searchtree1 a Tip=False
    if (arg2.is_Tip()) {
        return false;
    }

    // searchtree1 a (Node left x right) = (a= x \<or> (searchtree1 a left)\<or> (searchtree1 a right))
    auto a = std::move(arg1);
    auto left = std::move(*arg2.as_Node().p1_);
    auto x = std::move(arg2.as_Node().p2_);
    auto right = std::move(*arg2.as_Node().p3_);
    return (a == x) || (searchtree1(a, std::move(left)) || searchtree1(std::move(a), std::move(right)));
}
