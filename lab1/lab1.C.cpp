#include <iostream>

int NOD(int, int);

int main() {
    int A, B;

    std::cin >> A >> B;

    std::cout << NOD(A, B);

    return 0;
}

int NOD(int a, int b) {
    return (b == 0) ? a : NOD(b, a%b);
}