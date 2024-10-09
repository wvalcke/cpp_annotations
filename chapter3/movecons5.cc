// C++ Program to illustrate the use of
// noexcept move constructor
#include <vector>
#include <iostream>
using namespace std;

class Test {
public:
    Test(){}
      
    // Move constructor marked as noexcept
    Test(Test&& other) noexcept {
        cout << "Move constructor  " << endl;
    }

    // Copy constructor
    Test(const Test& other) {
        cout << "Copy constructor  " << endl;
    }
};

int main() {
    vector<Test> vec;

    vec.reserve(2);  // Reserve space for at least two elements

  //Test a;

    vec.push_back(Test());
    vec.push_back(Test());  // Uses the move constructor

    cout << "Resize happens" << endl;
    vec.push_back(Test());
    
    return 0;
}
