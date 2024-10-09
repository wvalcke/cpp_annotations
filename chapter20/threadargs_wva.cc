#include <iostream>
#include <thread>

using namespace std;

struct NoMove
{
    NoMove() = default;
    NoMove(NoMove &&tmp) = delete;
    /* normaal is volgende lijn er niet (zie verder voor uitleg)*/
    NoMove(NoMove const& other) = default;
};

struct MoveOK
{
    int d_value = 10;

    MoveOK()
    {
        cout << "MoveOK constructor\n";
    }
    MoveOK(MoveOK const &other)
    : d_value(other.d_value)
    {
        cout << "MoveOK copy constructor\n";
    }

    MoveOK(MoveOK &&tmp)
    {
        d_value = 10;
        tmp.d_value = 0;
        cout << "MoveOK move cons.\n";
    }
};

void valueArg(int value)
{}
void refArg(int &ref)
{}
void r_refArg(int &&tmp)
{
    tmp = 100;
}
void r_refNoMove(NoMove &&tmp)
{}
void r_refMoveOK(MoveOK &&tmp)
{}

int main()
{
    int value = 0;

    std::thread(valueArg,   value).join();
    std::thread(refArg,     ref(value)).join();
    std::thread(r_refArg,   move(value)).join();
    cout << "value after r_refArg: " << value << '\n';

    //std::thread(refArg,     value);

    std::thread(r_refArg,   value).join();
    cout << "value after r_refArg: " << value << '\n';
// deze lijn compileert niet als we geen copy constructor hebben
// of geen move constructor hebben
  std::thread(r_refNoMove, NoMove()).join();

    NoMove noMove;
// volgende lijn compileert niet als we geen copy constructor hebben
    NoMove otherNoMove(noMove);
// volgende lijn compileert niet als we geen move constructor of copy constructor
// hebben
  std::thread(r_refNoMove, noMove).join();

    MoveOK moveOK;

    std::thread(r_refMoveOK, moveOK).join();
    cout << moveOK.d_value << '\n';

    std::thread(r_refMoveOK, move(moveOK)).join();
    cout << moveOK.d_value << '\n';
}
