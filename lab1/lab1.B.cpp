//#include <iostream>
//#include <cmath>
//
//int main() {
//    int N, K;
//
//    std::cin >> N >> K;
//
//    if (!(
//            (1 <= N && N <= pow(10, 3)) &&
//            (pow(-10, 9) <= K && K <= pow(10, 9))
//    ))
//        return 0;
//
//    int * digits = new int[N];
//    for (int i = 0; i < N; i++) {
//        //digits[i] = i;
//        std::cin >> digits[i];
//        if (digits[i] > pow(10,9))
//            return 0;
//    }
//
//
//
//    if (abs(K) > N)
//    {
//        K = K%N;
//    }
//
//    if (K > 0) {
//        int temp;
//        for (int k = 0; k < K; k++) {
//            temp = digits[N-1];
//            for (int i = N - 1; i >= 0; i--) {
//                if (i - 1 < 0) {
//                    digits[i] = temp;
//                } else {
//                    digits[i] = digits[i - 1];
//                }
//            }
//        }
//    }
//    else if (K < 0)
//    {
//        int temp;
//        for (int k = 0; k < abs(K); k++) {
//            temp = digits[0];
//            for (int i = 0; i < N; i++) {
//                if (i + 1 > N-1)
//                {
//                    digits[i] = temp;
//                }
//                else
//                {
//                    digits[i] = digits[i+1];
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        std::cout << digits[i] << " ";
//    }
//
//    std::cout << std::endl;
//
//    delete [] digits;
//    return 0;
//}
//
//
