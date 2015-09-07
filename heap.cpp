#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename T>
void print(T const & in) {
    cout << "input: ";
    for (auto i = in.begin(); i != in.end(); i++) {
        cout << *i;
        if (i != in.end() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void swap(double& a, double& b) {
    double tmp = a;
    a = b;
    b = tmp;
}

class HeapSort {
private:
    std::vector<double> v;
    
    int findParent(int index) {
        return floor((index - 1) / 2);
    }

    int findLeft(int index) {
        return (2 * index + 1);
    }

    int findRight(int index) {
        return (2 * index + 2);
    }

    void build() {
        int length = v.size();
        for (int i = (length - 2) / 2; i >= 0; i--) {
            // recusive
            this->heapify(i, length);
            // loop
            //this->shift(i, length);
        }
    }
    
    void shift(int index, int len) {
        int i = index;
        int child = this->findLeft(i);
        while (child < len) {
            // find out which child is bigger and take its index
            if (child + 1 < len && v[child] < v[child + 1]) {
                child++;
            }
            // if root is bigger then does nothing
            if (v[i] >= v[child]) {
                break;
            } else {
                // swap with root
                swap(v[i], v[child]);
                // check from the child index
                i = child;
                child = this->findLeft(i);
            }
        }
    }

    void heapify(int index, int size) {
        int left = this->findLeft(index);
        int right = this->findRight(index);
        int pivot = index;

        if (left < size) {
            if (v[left] > v[pivot]) {
                pivot = left;
            }
        }

        if (right < size) {
            if (v[right] > v[pivot]) {
                pivot = right;
            }
        }

        if (pivot != index) {
            swap(v[index], v[pivot]);
            heapify(pivot, size);
        }
    }

    void sort() {
        this->build();
        for (int i = v.size() - 1; i >= 0; i--) {
            swap(v[0], v[i]);
            heapify(0, i);
        }

    }
public:
    HeapSort() {
        v = {33.0, 44.0, 55.0, 66.0, 77.0, 88.0, 99.0, 11.0, 22.0};
    }

    void test() {
        print(v);
        this->build();
        print(v);
        this->sort();
        print(v);
    }
};

int main() {

    HeapSort test;
    test.test();

    return 0;
}

