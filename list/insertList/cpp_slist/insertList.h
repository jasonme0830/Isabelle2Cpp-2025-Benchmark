#include "../../../AgenType/newType.h"




template<typename T1>
slist<T1> Insert(T1 arg1, slist<T1> arg2) {
    // Insert a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = arg1;
        auto temp0 = slist<T1>::sCons(
            std::move(a),
            slist<T1>::sNil()
        );
        return temp0;
    }

    // Insert a (sCons x xs) =(if a \<le> x then (sCons a (sCons x xs)) else (sCons x (Insert a xs)))
    auto a = std::move(arg1);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    slist<T1> temp0;
    if (a <= x) {
        auto temp1 = slist<T1>::sCons(
            std::move(x),
            std::move(xs)
        );
        auto temp2 = slist<T1>::sCons(
            std::move(a),
            std::move(temp1)
        );
        temp0 = std::move(temp2);
    } else {
        auto temp3 = slist<T1>::sCons(
            std::move(x),
            Insert(std::move(a), std::move(xs))
        );
        temp0 = std::move(temp3);
    }
    return temp0;
}

