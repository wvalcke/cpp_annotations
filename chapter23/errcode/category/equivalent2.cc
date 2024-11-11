//#define XERR
#include "category.ih"

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0824r1.html:
// Two error_code instances compare equal if and only if they represent the
// same error enumerator in the same domain.
    // Each "error domain" is represented in code by an object of type
// std::error_category.

// compare `condition' to an error condition constructed from the
// error condition constructed from the category matching the provided
// error code

//equiv
bool Category::equivalent(int ev, error_condition const &condition)
                                                        const noexcept
{
    if (ev == 0)                                    // no error? then
        return condition.category() == *this and    // categories must
               not static_cast<bool>(condition);    // be equal and
                                                    // condition must
                                                    // indicate no error

    auto iter = s_map.find(as<CatErr>(ev));     // find ev's Cond

    return iter == s_map.end()?
                false                           // no such CatErr
            :                                   // or compare conditions
                condition == make_error_condition(iter->second.cond);
}
//=
