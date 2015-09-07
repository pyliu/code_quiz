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
    void swap(vector<int>& in, int index1, int index2) {
        // swap 2 variables without additional temp variable
        in[index1] = in[index1] ^ in[index2];
        in[index2] = in[index1] ^ in[index2];
        in[index1] = in[index1] ^ in[index2];
    }

    void makeHeap(vector<int>& in, int st, int ed) {
        int child = ed;
        while (child > st) {
            int parent = floor((child - 1) / 2);
            if (in[parent] < in[child]) {
                swap(in, parent, child);
                // loolk up
                child = parent;
            } else {
                return;
            }
        }
    }

    void heapify(vector<int>& in, int count) {
        if (count < 2) return;
        int ed = 1;
        while (ed < count) {
            makeHeap(in, 0, ed);
            ed++;
        }
    }

    void sort(vector<int>& in) {
        heapify(in, in.size());
        int end = in.size() - 1;
        while (end > 0) {
            swap(in, 0, end);
            heapify(in, end);
            end--;
        }
    }

public:
    void test() {
        cout << "original vector:" << endl;
        vector<int> heap = {2, 4, 55, 67, 100, 23, 1, 9, 10, 11, 24, 46, 78, 88, 99};
        print(heap);
        auto heap_std = heap;

        cout << "heapify vector:" << endl;
        heapify(heap, heap.size());
        print(heap);

        cout << "sorted vector:" << endl;
        sort(heap);
        print(heap);

        cout << "heap std:" << endl;
        print(heap_std);

        make_heap(heap_std.begin(), heap_std.end());
        cout << "heap std heapified:" << endl;
        print(heap_std);

        sort_heap(heap_std.begin(), heap_std.end());
        cout << "heap std heap sorted:" << endl;
        print(heap_std);
    }
};

class HeapSort2 {
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
    HeapSort2() {
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

    HeapSort2 test2;
    test2.test();

    return 0;
}

