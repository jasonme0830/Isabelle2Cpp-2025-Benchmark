#include "../../../AgenType/newType.h"


//insertTree
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


//changeTree
template<typename T1>
tree<T1> changetree(const T1 &arg1, const T1 &arg2, const tree<T1> &arg3) {
    // changetree a b Tip = Tip
    if (arg3.is_Tip()) {
        return tree<T1>::Tip();
    }

    // changetree a b (Node left x right) = ( if (a=x) then (Node left b right) ...
    auto a = arg1;
    auto b = arg2;
    auto left = arg3.as_Node().p1();
    auto x = arg3.as_Node().p2();
    auto right = arg3.as_Node().p3();
    tree<T1> temp2;
    if (a == x) {
        temp2 = tree<T1>::Node(left, b, right);
    } else {
        tree<T1> temp5;
        if (a < x) {
            temp5 = tree<T1>::Node(changetree(a, b, left), x, right);
        } else {
            temp5 = tree<T1>::Node(left, x, changetree(a, b, right));
        }
        temp2 = temp5.self();
    }
    return temp2;
}


