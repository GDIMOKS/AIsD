#include <iostream>
#include <vector>
#include <string>

bool checkText(std::string text, int firstWordBegin, int secondWordBegin, int length) {
    if (text.substr(firstWordBegin, length) == text.substr(secondWordBegin, length))
        return true;
    return false;
}

int main() {

    int N, M;

    std::cin >> N >> M;

    char * text = new char[N+1];

    for (int i = 0; i < N; i++) {
        std::cin >> text[i];
    }
    text[N] = '\0';

    int fansIsTrue = 0;

    for (int l = 0; l < M; l++) {
        int i, j, k;

        std::cin >> i >> j >> k;

        if (checkText(text, i-1, j-1, k))
            fansIsTrue++;

    }

    std::cout << fansIsTrue;

    delete [] text;

    return 0;
}