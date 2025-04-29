#include "../../../AgenType/newType.h"
#include <iostream>


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
    struct timespec start, one, two;
    timespec_get(&start, TIME_UTC);

    // rightest (Node left x right) = (if right=Tip then x  ...
    auto x = std::move(arg1.as_Node().p2_);
    auto right = std::move(*arg1.as_Node().p3_);
    T1 temp0;

    if (right.is_Tip()) {
        timespec_get(&one, TIME_UTC);
        temp0 = std::move(x);
        timespec_get(&two, TIME_UTC);
    } else {
        timespec_get(&one, TIME_UTC);
        temp0 = rightest(std::move(right));
        // temp0 = rightest(right);
        timespec_get(&two, TIME_UTC);
    }

    long long elapsed_one = (one.tv_sec - start.tv_sec) * 1000000000LL + (one.tv_nsec - start.tv_nsec);
    long long elapsed_two = (two.tv_sec - start.tv_sec) * 1000000000LL + (two.tv_nsec - start.tv_nsec);
    std::cout << "   one Time: " << elapsed_one <<" ns";
    std::cout << "   two Time: " << elapsed_two <<" ns"<<std::endl;
    return temp0;
}

template<typename T1>
tree<T1> test(tree<T1> arg1){
    return arg1;
}