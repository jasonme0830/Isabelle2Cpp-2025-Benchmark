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
T1 rightest(tree<T1> arg1) {
    // rightest (Node left x right) = (if right=Tip then x  ...
    auto x = std::move(arg1.as_Node().p2_);
    auto right = std::move(*arg1.as_Node().p3_);
    T1 temp0;
    if (right.is_Tip()) {
        temp0 = std::move(x);
    } else {
        temp0 = rightest(std::move(right));
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

template<typename T1>
tree<T1> deltreeroot(tree<T1> arg1) {
    // deltreeroot Tip = Tip
    if (arg1.is_Tip()) {
        return tree<T1>::Tip();
    }

    // deltreeroot (Node left x right) =(if right=Tip  ...
    auto left = std::move(*arg1.as_Node().p1_);
    auto right = std::move(*arg1.as_Node().p3_);
    tree<T1> temp0;
    if (right.is_Tip()) {
        temp0 = std::move(left);
    } else {
        tree<T1> temp1;
        if (left.is_Tip()) {
            temp1 = std::move(right);
        } else {
            auto temp2 = left;
            auto temp3 = left;
            auto temp4 = tree<T1>::Node(
                delRightest(std::move(temp2)),
                rightest(std::move(temp3)),
                std::move(right)
            );
            temp1 = std::move(temp4);
        }
        temp0 = std::move(temp1);
    }
    return temp0;
}

template<typename T1>
tree<T1> deltree(T1 arg1, tree<T1> arg2) {
    // deltree a Tip = Tip
    if (arg2.is_Tip()) {
        return tree<T1>::Tip();
    }

    // deltree a (Node left x right) =( if a=x then(deltreeroot(Node left x right)) ...
    auto a = std::move(arg1);
    auto left = std::move(*arg2.as_Node().p1_);
    auto x = std::move(arg2.as_Node().p2_);
    auto right = std::move(*arg2.as_Node().p3_);
    tree<T1> temp0;
    if (a == x) {
        auto temp1 = tree<T1>::Node(
            std::move(left),
            std::move(x),
            std::move(right)
        );
        temp0 = deltreeroot(std::move(temp1));
    } else {
        tree<T1> temp2;
        if (a < x) {
            auto temp3 = tree<T1>::Node(
                deltree(std::move(a), std::move(left)),
                std::move(x),
                std::move(right)
            );
            temp2 = std::move(temp3);
        } else {
            auto temp4 = tree<T1>::Node(
                std::move(left),
                std::move(x),
                deltree(std::move(a), std::move(right))
            );
            temp2 = std::move(temp4);
        }
        temp0 = std::move(temp2);
    }
    return temp0;
}
