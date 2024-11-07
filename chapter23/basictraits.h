#ifndef INCLUDED_BASICTRAITS_H_
#define INCLUDED_BASICTRAITS_H_

    template <typename TypeParam>
    class BasicTraits
    {
//BASIC
        template <typename T>
        struct Basic
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = false,
                isRef = false,
                isRRef = false
            };
        };
//=
        template <typename T>
        struct Basic<T const>
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = true,
                isRef = false,
                isRRef = false
            };
        };
//POINTER
        template <typename T>
        struct Basic<T *>
        {
            using Type = T;
            enum
            {
                isPointer = true,
                isConst = false,
                isRef = false,
                isRRef = false
            };
        };
//=
//CONST
        template <typename T>
        struct Basic<T const *>
        {
            using Type = T;
            enum
            {
                isPointer = true,
                isConst = true,
                isRef = false,
                isRRef = false
            };
        };
//=
        template <typename T>
        struct Basic<T &>
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = false,
                isRef = true,
                isRRef = false
            };
        };

        template <typename T>
        struct Basic<T const &>
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = true,
                isRef = true,
                isRRef = false
            };
        };
        template <typename T>
        struct Basic<T &&>
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = false,
                isRef = false,
                isRRef = true
            };
        };
        template <typename T>
        struct Basic<T const &&>
        {
            using Type = T;
            enum
            {
                isPointer = false,
                isConst = true,
                isRef = false,
                isRRef = true
            };
        };

        public:
            BasicTraits(BasicTraits const &other) = delete;

            using ValueType = typename Basic<TypeParam>::Type;
            using PtrType = ValueType *;
            using RefType = ValueType &;
            using RvalueRefType = ValueType &&;

            enum
            {
                isPointerType = Basic<TypeParam>::isPointer,
                isReferenceType = Basic<TypeParam>::isRef,
                isRvalueReferenceType = Basic<TypeParam>::isRRef,
                isConst = Basic<TypeParam>::isConst,

                isPlainType = not (isPointerType or isReferenceType or
                                   isRvalueReferenceType or isConst)
            };

    };

#endif
