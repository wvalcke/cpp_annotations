#include <iostream>
#include <unordered_map>
    
using namespace std;

int main(int argc, char* argv[])
{
    unordered_map<int, int> myMap = {{1, 2}, {3, 5}, {-8, 12}};

    cout << distance(++myMap.begin(), myMap.end()) << '\n'; // shows: 2
}
