//#include <iostream>
//#include <cmath>
//
//void DecToBin (bool*, unsigned long long, int&);
//void Log(unsigned long long, int, int&);
//void CheckDay(unsigned long long &value, int &current, int &prev, int &counter);
//
//int main() {
////    std::ios::sync_with_stdio(false);
////    std::cin.tie(nullptr);
//    long long X, Y;
//
//    std::cin >> X >> Y;
//
//    if (!(1 <= X && X <= Y && Y <= pow(10,18))) {
//        return 0;
//    }
//    long long daysCount = 0;
//
//
//
//    for (long long i = X; i <= Y; i++) {
//        int localCount = 0;
//        int prev = -1, current = -1;
//        long long value = i;
//
//        for (;value != 1 && value != 0;) {
//            if (localCount > 3)
//                break;
//            if (current != -1)
//                prev = current;
//
//            current = value % 2;
//
//            if (prev != current) {
//                localCount++;
//            }
//
//            prev = current;
//            value /= 2;
//            if (value == 1 || value == 0) {
//                if (prev != value)
//                    localCount++;
//            }
//        }
//        if (localCount == 3)
//        {
//            daysCount++;
//            std::cout << i << ", ";
//        }
//    }
//    std::cout << "\n";
//
//    std::cout << daysCount;
//
//    return 0;
//}
//
//void Log(unsigned long long value, int base, int& result) {
//result++;
//
//if (value == 1 || value == 0) {
//return;
//} else {
//Log(value/2, base, result);
//}
//}
//
//void CheckDay(unsigned long long &value, int &current, int &prev, int &counter) {
////    std::cout << value << " % 2 = " << value % 2 << "\n";
//if (current != -1) {
//prev = current;
//}
//
//current = value % 2;
//if (value == 1 || value == 0) {
////        std::cout << 1 << ") " << prev << " " << current << " " << value << "\n";
//
//prev = value % 2;
//return;
//} else {
////        std::cout << 2 << ") " << prev << " " << current << " " << value << "\n";
//if (prev != current)
//counter++;
//if (prev == -1)
//counter++;
//value /= 2;
//CheckDay(value, current, prev, counter);
//
//
////        std::cout << 3 << ") " << prev << " " << current << " " << value << "\n";
//
//
//}
//}
//
//void DecToBin(bool * digit, unsigned long long value, int& iterator) {
//if (value == 1 || value == 0) {
//digit[iterator] = value % 2;
//iterator++;
//return;
//} else {
//digit[iterator] = value % 2;
//iterator--;
//DecToBin(digit, value/2, iterator);
//}
//}
//
//
//
