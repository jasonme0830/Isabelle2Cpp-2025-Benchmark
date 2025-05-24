#include "../../../AgenType/newType.h"


template<typename T1>
tree<T1> inserttree(const T1 &arg1, const tree<T1> &arg2) {
    // inserttree a Tip = Node Tip a Tip
    if (arg2.is_Tip()) {
        auto a = arg1;
        return tree<T1>::Node(tree<T1>::Tip(), a, tree<T1>::Tip());
    }

    // inserttree a (Node left x right) = (if a\<le>x then (Node (inserttree a left) x right)  ...
    auto a = arg1;
    auto left = arg2.as_Node().p1();
    auto x = arg2.as_Node().p2();
    auto right = arg2.as_Node().p3();
    tree<T1> temp2;
    if (a <= x) {
        temp2 = tree<T1>::Node(inserttree(a, left), x, right);
    } else {
        temp2 = tree<T1>::Node(left, x, inserttree(a, right));
    }
    return temp2;
}


template<typename T1>
tree<T1> copytree(const tree<T1> &arg1) {
    // copytree (Node left x right) = Node (copytree left) x (copytree right)
    if (arg1.is_Node()) {
        auto left = arg1.as_Node().p1();
        auto x = arg1.as_Node().p2();
        auto right = arg1.as_Node().p3();
        return tree<T1>::Node(copytree(left), x, copytree(right));
    }

    // copytree Tip = Tip
    return tree<T1>::Tip();
}

