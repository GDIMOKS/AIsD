//#include <iostream>
//
//int main() {
//    int N;
//
//    std::cin >> N;
//
//    int * x = new int[N] {};
//    bool * walls = new bool[N] {};
//
//    for (int i = 0; i < N; i++) {
//        std::cin >> x[i];
//    }
//
//    if (N == 1)
//        std::cout << 1;
//
//    int wallsCount = 0;
//
//    for (int i = 0; i < N; i++) {
//        int j = i-1, k = i+1;
//        if (i == 0)
//            j = N-1;
//        else if (i == N-1)
//            k = 0;
//
//        std::cout << x[j] << " & " << x[i] << " = " << (x[i] & x[j]) << "\n";
//        if (!walls[j]) {
//            if ((x[i] & x[j]) != 0) {
//                walls[j] = true;
//            }
//        }
//        std::cout << x[i] << " & " << x[k] << " = " << (x[i] & x[k]) << "\n";
//        if (!walls[k]) {
//            if ((x[i] & x[k]) != 0) {
//                walls[k] = true;
//            }
//        }
//        std::cout << "\n";
//
//
//    }
//
//    for (int i = 0; i < N; i++) {
//        std::cout << i << " " << walls[i] << "\n";
//        if (walls[i])
//            wallsCount++;
//    }
//
//    if (wallsCount == 0)
//        wallsCount++;
//
//    std::cout << wallsCount;
//
//    delete [] x;
//    delete [] walls;
//
//    return 0;
//}
