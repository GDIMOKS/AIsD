#include <iostream>

struct Data {
    long long value;

    Data() {
        value = 0;
    }
    Data(long long _value) : Data() {
        value = _value;
    }
};
struct Data2 {
    long long startTime;
    long long finishTime;
    long long cook;
    Data2() {};
    Data2(long long _startTime, long long _finishTime, long long _cook) {
        startTime = _startTime;
        finishTime = _finishTime;
        cook = _cook;
    }
};
struct Heap2 {
    long long size;
    long long maxSize;
    Data2 * data;
    Heap2() {
        size = 0;
    }
    Heap2(long long _maxSize) : Heap2() {
        maxSize = _maxSize;
        data = new Data2[maxSize];
    }
    ~Heap2() {
        delete [] data;
    }

    void siftUp(long long index) {
        while(data[index].finishTime+data[index].startTime < data[(index-1)/2].finishTime+data[(index-1)/2].startTime) {
            std::swap(data[index], data[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void siftDown(long long index, long long _size, bool mode = true) {
        long long j = index;
        long long left = 2*index+1;
        long long right = 2*index+2;

        if (mode) {
            if (left < _size && data[j].finishTime+data[j].startTime > data[left].finishTime+data[left].startTime) {
                j = left;
            }
            if (right < _size && data[j].finishTime+data[j].startTime > data[right].finishTime+data[right].startTime) {
                j = right;
            }
        } else {
            if (left < _size && data[j].finishTime+data[j].startTime < data[left].finishTime+data[left].startTime) {
                j = left;
            }
            if (right < _size && data[j].finishTime+data[j].startTime < data[right].finishTime+data[right].startTime) {
                j = right;
            }
        }

        if (index != j) {
            std::swap(data[index], data[j]);
            siftDown(j, _size, mode);
        }
    }

    Data2 extractMin() {
        if (size == 0)
            return {};
        Data2 min = data[0];
        data[0] = data[size-1];
        size--;
        siftDown(0, size);
        return min;
    }
    void insert(Data2 & _data) {
        data[size] = _data;
        size++;
        if (size != 1)
            siftUp(size-1);
    }
    void print() {
        for (long long i = 0; i < size; i++) {
            std::cout << "(" << data[i].cook << "; " << data[i].finishTime+data[i].startTime << ") ";
        }
        std::cout << "\n";
    }
};

struct Heap {
    long long size;
    long long maxSize;
    long long * values;

    Heap() {
        size = 0;
    }
    Heap(long long _maxSize) : Heap() {
        maxSize = _maxSize;
        values = new long long[maxSize];
    }
    ~Heap() {
        delete [] values;
    }

    void siftUp(long long index) {
        while(values[index] < values[(index-1)/2]) {
            std::swap(values[index], values[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void siftDown(long long index, long long _size, bool mode = true) {
        long long j = index;
        long long left = 2*index+1;
        long long right = 2*index+2;

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

    long long extractMin() {
        if (size == 0)
            return 0;
        long long min = values[0];
        values[0] = values[size-1];
        size--;
        siftDown(0, size);
        return min;
    }
    void insert(long long value) {
        values[size] = value;
        size++;
        if (size != 1)
            siftUp(size-1);
    }



    void print() {
        for (long long i = 0; i < size; i++) {
            std::cout << values[i] << " ";
        }
        std::cout << "\n";
    }
};




int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, m;
    long long sumSalary = 0;
    std::cin >> n >> m;
    Heap * freeMasters = new Heap(n);


    for (long long i = 0; i < n; i++) {
        long long salary;
        std::cin >> salary;
        freeMasters->insert(salary);
    }

    Heap2 * orders = new Heap2(m);

    for (long long i = 0; i < m; i++) {
        long long t = 0, f = 0;
        std::cin >> t >> f;

        while (orders->size != 0 && orders[0].data->finishTime+orders[0].data->startTime <= t) {
            Data2 min = orders->extractMin();
            freeMasters->insert(min.cook);

        }

        if (freeMasters->size != 0) {

            Data2 data2 = Data2(t, f, freeMasters->extractMin());
            orders->insert(data2);
            sumSalary += data2.cook * f;
        }

    }
    std::cout << sumSalary << "\n";


    delete freeMasters;
    delete orders;

    return 0;
}

