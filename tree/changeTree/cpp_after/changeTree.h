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
tree<T1> changetree(T1 arg1, T1 arg2, tree<T1> arg3) {
    // changetree a b Tip = Tip
    if (arg3.is_Tip()) {
        return tree<T1>::Tip();
    }

    // changetree a b (Node left x right) = ( if (a=x) then (Node left b right) ...
    auto a = std::move(arg1);
    auto b = std::move(arg2);
    auto left = std::move(*arg3.as_Node().p1_);
    auto x = std::move(arg3.as_Node().p2_);
    auto right = std::move(*arg3.as_Node().p3_);
    tree<T1> temp0;
    if (a == x) {
        auto temp1 = tree<T1>::Node(
            std::move(left),
            std::move(b),
            std::move(right)
        );
        temp0 = std::move(temp1);
    } else {
        tree<T1> temp2;
        if (a < x) {
            auto temp3 = tree<T1>::Node(
                changetree(std::move(a), std::move(b), std::move(left)),
                std::move(x),
                std::move(right)
            );
            temp2 = std::move(temp3);
        } else {
            auto temp4 = tree<T1>::Node(
                std::move(left),
                std::move(x),
                changetree(std::move(a), std::move(b), std::move(right))
            );
            temp2 = std::move(temp4);
        }
        temp0 = std::move(temp2);
    }
    return temp0;
}


