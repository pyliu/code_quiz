#include <iostream>

using namespace std;

int main() {
    auto test = "1234";
    cout << "the test type: " << typeid(test).name() << endl;
    return 0;
}

