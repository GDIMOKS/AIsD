#include <iostream>



int main() {

    int N;

    std::cin >> N;

    if (!(1 <= N && N <= 10*10*10*10*10*10))
        return 0;

    char * word = new char[N];
    for (int i = 0; i < N; i++) {
        std::cin >> word[i];
    }
    bool isPalindrome = true;

    for (int i = 0; i < N/2; i++) {

        if (word[i] != word[N-1-i]) {
            isPalindrome = false;

            bool * isCanBePalindrome = new bool [N-(2*i)] {};

            for (int j = i, k = 0; j <= N-1-i; j++, k++) {
                for (int left = i, right = N-i-1; left <= right; left++, right--) {
                    if (left == j)
                        left++;
                    if (right == j)
                        right--;
//                    std::cout << word[left] << " " << word[right] << "\n";
                    if (word[left] != word[right]) {
                        isCanBePalindrome[k] = false;
                        break;
                    } else {
                        isCanBePalindrome[k] = true;
                    }
                }
            }
/*            std::cout << N-(2*i) << "\n";
            for (int j = 0; j < N-(2*i); j++) {
                std::cout << isCanBePalindrome[j] << " ";
            }
            std::cout << "\n";*/
            for (int j = 0; j < N-(2*i); j++) {
                if (isCanBePalindrome[j])
                    isPalindrome = true;
            }

            delete [] isCanBePalindrome;

            break;
        }
    }


    if (isPalindrome)
        std::cout << "YES";
    else
        std::cout << "NO";


    delete [] word;
    return 0;
}



