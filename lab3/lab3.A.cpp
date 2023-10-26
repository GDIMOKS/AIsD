//#include <iostream>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int n;
//    bool isHeap = true;
//
//    std::cin >> n;
//    int * values = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        std::cin >> values[i];
//    }
//
//    for (int i = 0; i < n; i++) {
//        int j = 2*i+1;
//
//        if (j < n) {
////            std::cout << i << ": " << values[i] << " " << j << ": " << values[j] << "\n";
//            if (values[i] > values[j]) {
//                isHeap = false;
//                break;
//            }
//        }
//        j = 2*i+2;
//
//        if (j < n) {
////            std::cout << i << ": " << values[i] << " " << j << ": " << values[j] << "\n";
//            if (values[i] > values[j]) {
//                isHeap = false;
//                break;
//            }
//        }
//    }
//
//    if (isHeap)
//        std::cout << "YES";
//    else
//        std::cout << "NO";
//
//    return 0;
//}
//
