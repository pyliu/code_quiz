#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    vector<int> res(digits.size(), 0);
    int sum = 0;
    int one = 1;
    for(int i =  digits.size() - 1; i >= 0; i--) {
        sum = one + digits[i];
        one = sum / 10;
        res[i] = sum % 10;
    }

    if(one > 0) {
        res.insert(res.begin(), one);
    }
    return res;
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
    auto result = plusOne(test);
    print(result);
    return 0;
}

