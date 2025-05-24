#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> app(const slist<T1> &arg1, const slist<T1> &arg2) {
    // app sNil as =as
    if (arg1.is_sNil()) {
        auto as = arg2.self();
        return as;
    }

    // app(sCons a as ) bs= sCons a (app as bs)
    auto a = arg1.as_sCons().p1();
    auto as = arg1.as_sCons().p2();
    auto bs = arg2.self();
    return slist<T1>::sCons(a, app(as, bs));
}


template<typename T1>
slist<T1> Reverse(const slist<T1> &arg1) {
    // Reverse sNil = sNil
    if (arg1.is_sNil()) {
        return slist<T1>::sNil();
    }

    // Reverse (sCons a as) = app(Reverse as)(sCons a sNil)
    auto a = arg1.as_sCons().p1();
    auto as = arg1.as_sCons().p2();
    auto temp0 = Reverse(as);
    return app(temp0, slist<T1>::sCons(a, slist<T1>::sNil()));
}

