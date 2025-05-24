#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> ModifyValue(const T1 &arg1, const T1 &arg2, const slist<T1> &arg3) {
    // ModifyValue a b sNil = sNil
    if (arg3.is_sNil()) {
        return slist<T1>::sNil();
    }

    // ModifyValue a b (sCons x xs) = (if x=a then (sCons b (ModifyValue a b xs)) else (sCons x (ModifyValue a b xs)))
    auto a = arg1;
    auto b = arg2;
    auto x = arg3.as_sCons().p1();
    auto xs = arg3.as_sCons().p2();
    slist<T1> temp2;
    if (x == a) {
        temp2 = slist<T1>::sCons(b, ModifyValue(a, b, xs));
    } else {
        temp2 = slist<T1>::sCons(x, ModifyValue(a, b, xs));
    }
    return temp2;
}

