#include <iostream>
#include <vector>

int main() {
    std::string T;
    std::string X;

    std::getline(std::cin,T);
    std::getline(std::cin,X);

    long long count = 0;
    std::vector<int> indexes;

    if (T.size() >= X.size()) {
        for (int i = 0, m = X.size(); i < T.size() - X.size()+1; i++) {

            if (T.substr(i, m) == X) {
                indexes.push_back(i);
                count++;
            }

        }
    }

    std::cout << count << "\n";
    for (auto & index : indexes) {
        std::cout << index << " ";
    }


    return 0;
}