#include <iostream>

struct Heap {
    int size;
    int * values;

    Heap() {}
    Heap(int _size) : Heap() {
        size = _size;
        values = new int [size];
    }

    void siftDown(int index) {
        int j = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if (left < size && values[j] > values[left]) {
            j = left;
        }
        if (right < size && values[j] > values[right]) {
            j = right;
        }
        if (index != j) {
            std::swap(values[index], values[j]);
            siftDown(j);
        }
    }

    int extractMin() {
        if (size == 0)
            return 1000000001;
        int min = values[0];
        values[0] = values[size-1];
        size--;
        siftDown(0);
        return min;
    }

    void heapSort() {
        for (int i = size/2-1; i >= 0; i--) {
            siftDown(i);
        }
        for (int i = size-1; i >=0; i--) {
            std::swap(values[0], values[i]);
            siftDown(i);
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << values[i] << " ";
        }
        std::cout << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n;
    std::cin >> n;
    Heap * heap = new Heap(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heap->values[i];
    }
    heap->heapSort();
    heap->print();

    return 0;
}

