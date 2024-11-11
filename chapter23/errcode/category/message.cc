//#define XERR
#include "category.ih"

//msg
std::string Category::message(int ce) const
{
    auto iter = s_map.find(static_cast<CatErr>(ce));
    return iter != s_map.end() ? iter->second.msg : "No CatErr value";
}
//=
