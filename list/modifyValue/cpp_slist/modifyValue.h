#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> ModifyValue(T1 arg1, T1 arg2, slist<T1> arg3) {
    // ModifyValue a b sNil = sNil
    if (arg3.is_sNil()) {
        return slist<T1>::sNil();
    }

    // ModifyValue a b (sCons x xs) = (if x=a then (sCons b (ModifyValue a b xs)) else (sCons x (ModifyValue a b xs)))
    auto a = std::move(arg1);
    auto b = std::move(arg2);
    auto x = std::move(arg3.as_sCons().p1_);
    auto xs = std::move(*arg3.as_sCons().p2_);
    slist<T1> temp0;
    if (x == a) {
        auto temp1 = slist<T1>::sCons(
            b,
            ModifyValue(std::move(a), b, std::move(xs))
        );
        temp0 = std::move(temp1);
    } else {
        auto temp2 = slist<T1>::sCons(
            std::move(x),
            ModifyValue(std::move(a), std::move(b), std::move(xs))
        );
        temp0 = std::move(temp2);
    }
    return temp0;
}
