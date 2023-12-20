#include <iostream>

int main() {
    int N;

    std::cin >> N;

    int * x = new int[N] {};
    long fullSum = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> x[i];

        fullSum += x[i];
    }

    int optimalIndex = -1;
    long leftSum = 0;
    long rightSum = fullSum;

    for (int i = 0; i < N; i++) {
        rightSum -= x[i];

        if (leftSum == rightSum) {
            optimalIndex = i;
            break;
        }
        leftSum += x[i];
    }

    std::cout << optimalIndex;

    delete [] x;

    return 0;
}
