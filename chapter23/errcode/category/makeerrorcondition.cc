//#define XERR
#include "category.ih"

//make
std::error_condition make_error_condition(Cond ec)
{
    return { static_cast<int>(ec), Category::instance() };
}
//=
