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

public:
    HeapSort2() {
        v = {33.0, 44.0, 55.0, 66.0, 77.0, 88.0, 99.0, 11.0, 22.0};
    }

    void test() {
        print(v);
    }
};

int main() {
    
    HeapSort2 test2;
    test2.test();

    return 0;
}

