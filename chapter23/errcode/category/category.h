#ifndef INCLUDED_CATEGORY_
#define INCLUDED_CATEGORY_

#include <unordered_map>
#include <system_error>

//caterr
enum class CatErr
{
    Err1 = 1,           // causes of errors
    Err2,
    Err3
};
//=

//iscodeenum
namespace std
{
    template <>
    struct is_error_code_enum<CatErr>: public true_type
    {};
}
//=

std::error_code make_error_code(CatErr ce);

// -------------------------------------------------------------------

//cond
enum class Cond
{
    NoCond = -1,
    Cond1 = 1,
    Cond2,
    Cond3,
};
//=

//iscondenum
namespace std
{
    template <>
    struct is_error_condition_enum<Cond>: public true_type
    {};
}
//=

std::error_condition make_error_condition(Cond ec);

// -------------------------------------------------------------------

//category
class Category: public std::error_category
{
    static Category s_instance;
    struct POD
    {
        Cond        cond;
        char const *msg;
    };

    static std::unordered_map<CatErr, POD> s_map;

    public:
        Category(Category const &other) = delete;

        static Category &instance();

        bool equivalent(std::error_code const &ec, int condNr)
                                            const noexcept override;
        bool equivalent(int ev, std::error_condition const &condition)
                                            const noexcept override;
        std::error_condition default_error_condition(int ev)
                                            const noexcept override;

        std::string message(int ce) const override;
        char const *name() const noexcept override;

    private:
        Category() = default;

        template <typename Enum>
        static constexpr Enum as(int err);
};
//=


template <typename Enum>
inline constexpr Enum Category::as(int value)
{
    return static_cast<Enum>(value);
}

#endif
