#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> DelListHead(const slist<T1> &arg1) {
    // DelListHead (sCons x xs) = xs
    if (arg1.is_sCons()) {
        auto xs = arg1.as_sCons().p2();
        return xs;
    }

    // DelListHead sNil = sNil
    return slist<T1>::sNil();
}


template<typename T1>
slist<T1> DelListI(const std::uint64_t &arg1, const slist<T1> &arg2) {
    // DelListI i sNil = sNil
    if (arg2.is_sNil()) {
        return slist<T1>::sNil();
    }

    // DelListI i (sCons a sNil) = sNil
    if (arg2.is_sCons()) {
        if (arg2.as_sCons().p2().is_sNil()) {
            return slist<T1>::sNil();
        }
    }

    // DelListI Zero (sCons x xs) = DelListHead (sCons x xs)
    if (arg1 == 0) {
        if (arg2.is_sCons()) {
            auto x = arg2.as_sCons().p1();
            auto xs = arg2.as_sCons().p2();
            return DelListHead(slist<T1>::sCons(x, xs));
        }
    }

    // DelListI (Suc i) (sCons x xs) = sCons x  (DelListI i xs)
    auto i = arg1 - 1;
    auto x = arg2.as_sCons().p1();
    auto xs = arg2.as_sCons().p2();
    return slist<T1>::sCons(x, DelListI(i, xs));
}

