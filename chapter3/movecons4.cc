// C++ program to illustrate what happens when we
// don't use the noexcept move constructor
#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() {}
  
    // Move constructor not marked as noexcept
    A(A&& other) {
        cout << "Move constructor" << endl;
    }

    // Copy constructor
    A(const A& other) {
        cout << "Copy constructor" << endl;
    }
};

int main() {
    vector<A> v;

      // Reserve space for at least two elements to
    // avoid immediate resizing
    v.reserve(2);

    // Uses the move constructor for the temporary objects
    v.push_back(A());
    v.push_back(A());

      cout << "Resize happens" << endl;
    
    // Move constructor may be called again if resizing occurs
    v.push_back(A());
    
    return 0;
}
