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

//rightest
template<typename T1>
T1 rightest(const tree<T1> &arg1) {
    // rightest (Node left x right) = (if right=Tip then x  ...
    auto x = arg1.as_Node().p2();
    auto right = arg1.as_Node().p3();
    T1 temp2;
    if (right.is_Tip()) {
        temp2 = x;
    } else {
        temp2 = rightest(right);
    }
    return temp2;
}


//delRightest
template<typename T1>
tree<T1> delRightest(const tree<T1> &arg1) {
    // delRightest (Node left x Tip) = left
    if (arg1.is_Node()) {
        if (arg1.as_Node().p3().is_Tip()) {
            auto left = arg1.as_Node().p1();
            return left;
        }
    }

    // delRightest (Node left x right) = Node left x (delRightest right)
    if (arg1.is_Node()) {
        auto left = arg1.as_Node().p1();
        auto x = arg1.as_Node().p2();
        auto right = arg1.as_Node().p3();
        return tree<T1>::Node(left, x, delRightest(right));
    }

    // delRightest Tip = Tip
    return tree<T1>::Tip();
}

//delTreeRoot
template<typename T1>
tree<T1> deltreeroot(const tree<T1> &arg1) {
    // deltreeroot Tip = Tip
    if (arg1.is_Tip()) {
        return tree<T1>::Tip();
    }

    // deltreeroot (Node left x right) =(if right=Tip  ...
    auto left = arg1.as_Node().p1();
    auto right = arg1.as_Node().p3();
    tree<T1> temp2;
    if (right.is_Tip()) {
        temp2 = left.self();
    } else {
        tree<T1> temp5;
        if (left.is_Tip()) {
            temp5 = right.self();
        } else {
            temp5 = tree<T1>::Node(delRightest(left), rightest(left), right);
        }
        temp2 = temp5.self();
    }
    return temp2;
}



