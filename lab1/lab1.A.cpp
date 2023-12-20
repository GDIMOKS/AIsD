#include <iostream>
#include <cmath>

long add(long, long);

int main() {
    long A, B;

    std::cin >> A >> B;

    if (pow(-10, 11) <= A && A <= pow(10, 11) && pow(-10, 11) <= B && B <= pow(10, 11))
        std::cout << add(A,B);

    return 0;
}

long add(long A, long B) {
    return A+B;
}
