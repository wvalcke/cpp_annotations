//#define XERR
#include "category.ih"

Category Category::s_instance;

Category &Category::instance()
{
    return s_instance;
}
