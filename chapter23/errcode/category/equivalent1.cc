//#define XERR
#include "category.ih"

//equiv
bool Category::equivalent(std::error_code const &ec, int condNr)
                                                        const noexcept
{
    if (*this != ec.category())
        return false;

    if (ec.value() == 0)                            // no error in ec?
        return condNr == 0;                         // then condNr must
                                                    // also be 0

    auto iter = s_map.find(as<CatErr>(ec.value())); // info associated
                                                    // with ec's CatErr

    return iter == s_map.end() ?
                        false                       // not found or
                    :                               // compare Cond values
                        iter->second.cond == as<Cond>(condNr);
}
//=

/*************************************************************************

The error_category::equivalent() virtual function is used to determine
equivalence between error codes and conditions. In fact, there are two
overloads of the error_category::equivalent() function.

The first overload:

bool equivalent(error_code const &code,     int condition) const;
                ----------------------      ---------------
                arbitrary error             error condition
                code                        in the current
                                            cat

defines equivalence between error_conditions in the current category with
error_codes from any category.


The second:

bool equivalent(int code,       error_condition const &condition) const;
                ---------       ---------------
                error code      arbitrary error
                in the current  condition
                cat.

is used to establish equivalence between error_codes
    in the current category with arbitrary error_conditions.


Since you are creating custom error conditions, it is the first overload that
you must override.  Defining equivalence is simple: return true if you want an
error_code to be equivalent to your condition, otherwise return false.


If your intent is to abstract OS-specific errors, you might implement
error_category::equivalent() like this:

(api_category_impl::)
bool equivalent(std::error_code const &code, int condition) const
{
    switch (condition)
    {
        case api_error::name_not_found:
        return code == std::error_code(system_category());

        default:
        return false;
    }
}

bool equivalent(std::error_code const &code, int condition) const
{
    switch (condition)      // available condition
    {
        // map the error code enum values in the current class
        // on the conditions used in the current class and
        // verify that the error code values are equal to
        // the values of error_code code:

      case low_system_resources:         // the error condition
        return code == not_enough_memory
            || code == resource_unavailable_try_again
            || code == too_many_files_open
            || code == too_many_files_open_in_system;
      ...

      case api_error::no_such_entry:
        return code == std::errc::no_such_file_or_directory;

      default:
        return false;
  }
}

******************/
