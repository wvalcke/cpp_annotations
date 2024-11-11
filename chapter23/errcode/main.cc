//#define XERR
#include "main.ih"

void show(std::error_category &cat)
{
    std::cerr << cat.name() << '\n';    // show the name of the category
}

int main(int argc, char **argv)
try
{
    Category &cat  = Category::instance();

    cout << cat.name() << '\n';         // show the name of the category
    show(cat);                          // same, with overridden name()

    error_code ec = CatErr::Err2;       // initialize an error_code
    cout << ec.category().name() << "\n";
    ec = CatErr::Err2;                  // same, direct assignment
    cout << ec.category().name() << "\n";

                                        // same, using assign()
    ec.assign(static_cast<int>(CatErr::Err2), cat);

    cout <<
            "ec == Err2 ?  " << (ec == CatErr::Err2) << "\n"
            "ec == Err1 ?  " << (ec == CatErr::Err1) << "\n"
            "ec == Cond1 ? " << (ec == Cond::Cond1) << "\n"
            "ec == Cond2 ? " << (ec == Cond::Cond2) << "\n"
            "ec == Cond3 ? " << (ec == Cond::Cond3) << "\n"
            "ec == Cond  ? " << (ec == Cond{}) << "\n"
            "ec == errc ?  " << (ec == errc::not_enough_memory) << "\n"
// WC       "ec == 1     ? " << (ec == 1)           << "\n"
    ;

    cout << "error_code value: " << ec.value() <<
            ", equivalent called from error_code: " <<
            ec.category().equivalent(ec,  static_cast<int>(Cond::Cond1)) <<
                                                                        '\n';

    cout << "Enum value of Cond::NoCond = " <<
                error_condition{ Cond::NoCond }.value() << '\n';

    cout << "Default Cond value: " << (int)Cond{} << '\n';

    assert(ec != Cond::Cond1);          // OK, current Cond value == Cond2
    assert(ec == Cond::Cond2);          // OK, current Cond value == Cond2
    assert(ec != Cond{});               // OK,
    assert(ec == CatErr::Err2);
    // assert(ec == 2);                 // not OK: can't compare to int
    // assert(ec == CatErr::Err1);      // not OK: ec == Err2

    cout << ec.category().name() << '\n';   // name via category()

                                        // get the default error condition
    error_condition cond = ec.default_error_condition();

    error_condition nope{ 12, cat };    // validity not checked
    cout << nope.value() << '\n';       // shows 12

    cout << "Default error condition:\n"
            "   cat.:  " << cond.category().name() << "\n" // the cat. name
            "   value: " << cond.value() << "\n"        // CatErr's numeric value
            "    " << cond.message() << '\n';     // CatErr's name

    error_condition errCond{ Cond::Cond1 };

    cout << "Directly constructed error condition. Value = " <<
            errCond.value() << ", message = " << errCond.message() << '\n';

    cout << "Making error condition objects, showing their value:\n"
            "Cond::Cond1: " << make_error_condition(Cond::Cond1).value() <<
                                                                        "\n"
            "Cond::Cond2: " << make_error_condition(Cond::Cond2).value() <<
                                                                        '\n';
    throw system_error{ ec, "For demonstration purposes" };
}
catch (std::system_error const &se)
{
    std::cout << "System Error:\n"
                 "  what()       = " << se.what() << "\n"
                 "  (error_)code = " << se.code() << '\n';
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}
