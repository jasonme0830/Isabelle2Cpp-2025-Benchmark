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
tree<T1> delRightest(tree<T1> arg1) {
    // delRightest (Node left x Tip) = left
    if (arg1.is_Node()) {
        if (std::move(*arg1.as_Node().p3_).is_Tip()) {
            auto left = std::move(*arg1.as_Node().p1_);
            return left;
        }
    }

    // delRightest (Node left x right) = Node left x (delRightest right)
    if (arg1.is_Node()) {
        auto left = std::move(*arg1.as_Node().p1_);
        auto x = std::move(arg1.as_Node().p2_);
        auto right = std::move(*arg1.as_Node().p3_);
        auto temp0 = tree<T1>::Node(
            std::move(left),
            std::move(x),
            delRightest(std::move(right))
        );
        return temp0;
    }

    // delRightest Tip = Tip
    return tree<T1>::Tip();
}

