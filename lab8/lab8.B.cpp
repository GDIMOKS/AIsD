#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string spell;
    std::cin >> spell;


    std::vector<int> N(spell.length(), 0);

    for (int i = 1; i < spell.length(); i++) {
        int j = N[i - 1];

        while (j > 0 && spell[i] != spell[j]) {
            j = N[j - 1];
        }

        if (spell[i] == spell[j]) {
            j++;
        }

        N[i] = j;
    }

    for (int i = 0; i < spell.length(); i++) {
        std::cout << N[i] << " ";
    }

    return 0;
}