#include <iostream>

struct Heap {
    int size;
    int maxSize;
    int * values;

    Heap() {
        size = 0;
        maxSize = 20;
        values = new int[maxSize];
    }

    void addValues() {
        int * tempValues;
        maxSize *= 5;
        tempValues = new int[maxSize];
        for (int i = 0; i < size; i ++) {
            tempValues[i] = values[i];
        }
        if (size != 0)
            delete [] values;
        values = tempValues;
    }
    void siftUp(int index) {
        while(values[index] < values[(index-1)/2]) {
            std::swap(values[index], values[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void siftDown(int index, int _size, bool mode = true) {
        int j = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if (mode) {
            if (left < _size && values[j] > values[left]) {
                j = left;
            }
            if (right < _size && values[j] > values[right]) {
                j = right;
            }
        } else {
            if (left < _size && values[j] < values[left]) {
                j = left;
            }
            if (right < _size && values[j] < values[right]) {
                j = right;
            }
        }

        if (index != j) {
            std::swap(values[index], values[j]);
            siftDown(j, _size, mode);
        }
    }

    int extractMin() {
        if (size == 0)
            return 1000000001;
        int min = values[0];
        values[0] = values[size-1];
        size--;
        siftDown(0, size);
        return min;
    }
    void insert(int value) {
        if (size >= maxSize)
            addValues();
        values[size] = value;
        size++;
        if (size != 1)
            siftUp(size-1);
    }
    void merge(Heap *heap1, Heap *heap2) {
        for (int i = 0; i < heap1->size; i++) {
            insert(heap1->values[i]);
        }
        for (int i = 0; i < heap2->size; i++) {
            insert(heap2->values[i]);

        }

    }

    int search(int xValue, int index) {
        int j = index;

        if (index < size && values[j] == xValue)
            return j;

        int left = 2*index+1;
        int right = 2*index+2;

        if (left < size && values[left] == xValue)
            j = left;
        else if (right < size && values[right] == xValue)
            j = right;

        if (j != index)
            return j;


        j = -1;
        if (values[left] < xValue) {
            j = search(xValue, left);
        }

        if (j == -1)
            if (values[right] < xValue) {
                j = search(xValue, right);
            }
        return j;
    }
    void decreaseKey(int xValue, int yValue) {
        for (int i = 0; i < size; i++) {
            if (values[i] == xValue) {
                values[i] = yValue;
                siftUp(i);
                break;
            }
        }
    }

    void heapSort(bool mode = true) {
        for (int i = size/2-1; i >= 0; i--) {
            siftDown(i, size, mode);
        }

        for (int i = size-1; i >= 0; i--) {
            std::swap(values[0], values[i]);
            siftDown( 0,i, mode);
        }
    }

    void correctHeap() {
        for (int i = size/2 - 1; i >= 0; i--) {
            siftDown(i, size);
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << values[i] << " ";
        }
        std::cout << "\n";
    }
};

void addHeaps(Heap *&heaps, int &maxSize, int size) {
    Heap * tempHeaps;
    maxSize *= 5;
    tempHeaps = new Heap[maxSize];
    for (int i = 0; i < size; i ++) {
        tempHeaps[i] = heaps[i];
    }
    if (maxSize != 0)
        delete [] heaps;
    heaps = tempHeaps;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    std::string command;
    int maxSize = 20;
    Heap * heaps = new Heap[maxSize];
    int count = 0;

    while(std::cin >> command){
        int x,y,k,m;

        switch (command[0]) {
            case 'c':
                if (count >= maxSize)
                    addHeaps(heaps, maxSize, count);

                heaps[count] = Heap();
                count++;
                break;
            case 'i':
                std::cin >> k >> x;
                heaps[k].insert(x);
                break;
            case 'e':
                std::cin >> k;
                int result;
                result = heaps[k].extractMin();
                if (result == 1000000001)
                    std::cout << "*\n";
                else
                    std::cout << result << "\n";

                break;
            case 'm':
                std::cin >> k >> m;
                if (count >= maxSize)
                    addHeaps(heaps, maxSize, count);
                heaps[count] = Heap();
                heaps[count].merge(&heaps[k], &heaps[m]);

                count++;

                break;
            case 'd':
                std::cin >> k >> x >> y;
                heaps[k].decreaseKey(x,y);

                break;
        }

    }

    delete [] heaps;


    return 0;
}