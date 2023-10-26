//#include <iostream>
//
//void siftDown(int, int, int, bool);
//
//void heapSort(int *, int, bool);
//
//void print(int *, int);
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//
//    int n;
//    std::cin >> n;
//    int * values = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        std::cin >> values[i];
//    }
//    heapSort(values,n, true);
//    print(values, n);
//
//    return 0;
//}
//
//void siftDown(int * array, int index, int _size, bool mode = true) {
//    int j = index;
//    int left = 2*index+1;
//    int right = 2*index+2;
//
//    if (mode) {
//        if (left < _size && array[j] < array[left]) {
//            j = left;
//        }
//        if (right < _size && array[j] < array[right]) {
//            j = right;
//        }
//    } else {
//        if (left < _size && array[j] > array[left]) {
//            j = left;
//        }
//        if (right < _size && array[j] > array[right]) {
//            j = right;
//        }
//    }
//
//    if (index != j) {
//        std::swap(array[index], array[j]);
//        siftDown(array, j, _size, mode);
//    }
//}
//
//void heapSort(int * array, int size, bool mode = true) {
//    for (int i = size/2-1; i >= 0; i--) {
//        siftDown(array, i, size, mode);
//    }
//
//    for (int i = size-1; i >= 0; i--) {
//        std::swap(array[0], array[i]);
//        siftDown(array, 0,i, mode);
//    }
//}
//
//void print(int * array, int size) {
//    for (int i = 0; i < size; i++) {
//        std::cout << array[i] << " ";
//    }
//    std::cout << "\n";
//}
//
