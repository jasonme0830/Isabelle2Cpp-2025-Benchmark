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


//searchTree1
template<typename T1>
bool searchtree1(const T1 &arg1, const tree<T1> &arg2) {
    // searchtree1 a Tip = False
    if (arg2.is_Tip()) {
        return false;
    }

    // searchtree1 a (Node left x right) = (a= x \<or> (searchtree1 a left)\<or> (searchtree1 a right))
    auto a = arg1;
    auto left = arg2.as_Node().p1();
    auto x = arg2.as_Node().p2();
    auto right = arg2.as_Node().p3();
    return (a == x) || (searchtree1(a, left) || searchtree1(a, right));
}


