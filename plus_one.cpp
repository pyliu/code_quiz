#include <iostream>
#include <vector>

using namespace std;

void plusOne(vector<int> &digits) {
    int sum = 0;
    int one = 1;
    for(int i =  digits.size() - 1; i >= 0; i--) {
        sum = one + digits[i];
        one = sum / 10;
        digits[i] = sum % 10;
    }

    if(one > 0) {
        digits.insert(digits.begin(), one);
    }
}

void print(vector<int>& in) {
    cout << "input: ";
    for (vector<int>::iterator i = in.begin(); i != in.end(); i++) {
        cout << *i;
    }
    cout << endl;
}

int main() {
    vector<int> test = {1, 0, 0, 3};
    print(test);
    plusOne(test);
    print(test);
    return 0;
}

