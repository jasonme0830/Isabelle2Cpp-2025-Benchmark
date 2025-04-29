#include "../../../AgenType/newType.h"


template<typename T1>
slist<T1> AddListTail(T1 arg1, slist<T1> arg2) {
    // AddListTail a sNil =sCons a sNil
    if (arg2.is_sNil()) {
        auto a = std::move(arg1);
        auto temp0 = slist<T1>::sCons(
            std::move(a),
            slist<T1>::sNil()
        );
        return temp0;
    }

    // AddListTail a (sCons x xs) = sCons x  (AddListTail a xs )
    auto a = std::move(arg1);
    auto x = std::move(arg2.as_sCons().p1_);
    auto xs = std::move(*arg2.as_sCons().p2_);
    auto temp0 = slist<T1>::sCons(
        std::move(x),
        AddListTail(std::move(a), std::move(xs))
    );
    return temp0;
}

