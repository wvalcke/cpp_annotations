#ifndef INCLUDED_TYPETYPE_H_
#define INCLUDED_TYPETYPE_H_

template <typename TemplateType>
struct TypeType
{
    using Type = TemplateType;
};

#endif
