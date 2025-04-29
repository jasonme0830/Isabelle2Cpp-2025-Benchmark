#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> app(slist<T1> arg1, slist<T1> arg2) {
    // app sNil as =as
    if (arg1.is_sNil()) {
        auto as = std::move(arg2);
        return as;
    }

    // app(sCons a as ) bs= sCons a (app as bs)
    auto a = std::move(arg1.as_sCons().p1_);
    auto as = std::move(*arg1.as_sCons().p2_);
    auto bs = std::move(arg2);
    auto temp0 = slist<T1>::sCons(
        std::move(a),
        app(std::move(as), std::move(bs))
    );
    return temp0;
}

template<typename T1>
slist<T1> Reverse(slist<T1> arg1) {
    // Reverse sNil = sNil
    if (arg1.is_sNil()) {
        return slist<T1>::sNil();
    }

    // Reverse (sCons a as) = app(Reverse as)(sCons a sNil)
    auto a = std::move(arg1.as_sCons().p1_);
    auto as = std::move(*arg1.as_sCons().p2_);
    auto temp0 = Reverse(std::move(as));
    auto temp1 = slist<T1>::sCons(
        std::move(a),
        slist<T1>::sNil()
    );
    return app(std::move(temp0), std::move(temp1));
}
