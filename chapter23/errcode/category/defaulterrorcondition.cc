//#define XERR
#include "category.ih"

//def
std::error_condition Category::default_error_condition(int ev)
                                                        const noexcept
{
//=
        // in real cases: ev represents CatErr values, also check for
        // the upper limit, and each CatErr has its own Cond.
        // (e.g. map[ev].conditionValue)

//def
    auto iter = s_map.find(as<CatErr>(ev));

    return make_error_condition(
                iter == s_map.end() ? Cond::NoCond : iter->second.cond
            );
}
//=
