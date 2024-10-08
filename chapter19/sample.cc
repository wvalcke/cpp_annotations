#include <algorithm>
#include <iostream>
#include <random>
#include <string>

using namespace std;

int main()
{
    string src{ "abcdefghijklmnopqrstuvwxyz" };
    string dest;

    sample(src.begin(), src.end(), back_inserter(dest), 7, mt19937{});

    std::cout << "Seven random letters out of " << src << " : " <<
                                                   dest << '\n';
}
//  Could display:
//    Seven random letters out of abcdefghijklmnopqrstuvwxyz : bciorux
