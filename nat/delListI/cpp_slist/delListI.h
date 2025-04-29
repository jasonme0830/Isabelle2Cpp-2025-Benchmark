#include "../../../AgenType/newType.h"



template<typename T1>
slist<T1> DelListI(snat arg1, slist<T1> arg2) {
    // DelListI i sNil = sNil
    if (arg2.is_sNil()) {
        return slist<T1>::sNil();
    }

    // DelListI i (sCons a sNil) = sNil
    if (arg2.is_sCons()) {
        if (std::move(*arg2.as_sCons().p2_).is_sNil()) {
            return slist<T1>::sNil();
        }
    }

    // DelListI sZero (sCons x xs) = DelListHead (sCons x xs)
    if (arg1.is_sZero()) {
        if (arg2.is_sCons()) {
            auto x = std::move(arg2.as_sCons().p1_);
            auto xs = std::move(*arg2.as_sCons().p2_);
            auto temp0 = slist<T1>::sCons(
                std::move(x),
                std::move(xs)
            );
            return DelListHead(std::move(temp0));
        }
    }

    // DelListI (sSuc i) (sCons x xs) = sCons x  (DelListI i xs)
    auto i = std::move(*arg1.as_sSuc().p1_);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    auto temp0 = slist<T1>::sCons(
        std::move(x),
        DelListI(std::move(i), std::move(xs))
    );
    return temp0;
}
