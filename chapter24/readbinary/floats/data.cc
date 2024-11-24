#include "floats.ih"

void (Floats::*Floats::s_action[])() const =
{
    &Floats::read,
    &Floats::write
};
