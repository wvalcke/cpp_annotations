//#define XERR
#include "category.ih"

//make
std::error_code make_error_code(CatErr ce)
{
    return { static_cast<int>(ce), Category::instance() };
}
//=
