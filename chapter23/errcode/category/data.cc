//#define XERR
#include "category.ih"

//data
unordered_map<CatErr, Category::POD> Category::s_map =
{
    { CatErr::Err1, { Cond::Cond1, "Err1" } },
    { CatErr::Err2, { Cond::Cond2, "Err2" } },
    { CatErr::Err3, { Cond::Cond1, "Err3" } },
};
//=
