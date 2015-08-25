#include <iostream>

using namespace std;

int removeDuplicates(int a[], int len) {
    int index = 2;
    for (int i = 2; i < len; i++) {
        if (a[index - 2] != a[i]) {
            a[index++] = a[i];
        }
    }
    return index;
}

void print(int a[], int len) {
    cout << "The array items(" << len << "): ";
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "remove duplicates from a sorted integer array (allow 2 duplication at most)." << endl;

    int test[11] = {1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 6};
    
    cout << "== original ==" << endl;
    print(test, 11);
    
    int len = removeDuplicates(test, 11);

    cout << "== after ==" << endl;
    print(test, len);
    cout << "== after (all) ==" << endl;
    print(test, 11);

    cout << "time complexity is O(n) and space complexity is O(1)." << endl;
    return 0;
}

