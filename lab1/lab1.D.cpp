#include <iostream>
#include <cmath>

int main() {
    int n, m, q;

    std::cin >> n >> m >> q;

    if (!(1 <= n && n <= pow(10, 6) &&
          1 <= m && m <= pow(10, 6) &&
          1 <= q && q <= pow(10, 6) &&
          m*n <= pow(10,6))
            )
    {
        return 0;
    }

    bool ** series = new bool * [n] {};

    for (int i = 0; i < n; i++) {
        series[i] = new bool[m] {};
    }

    int k = n*m;
    for (int i = 0; i < q; i++) {
        int s, e;
        std::cin >> e >> s;
        if (!series[s - 1][e - 1]) {
            series[s-1][e-1] = true;
            k--;
        }
    }

    std::cout << k << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!series[i][j]) {
                std::cout << j+1 << " " << i+1;
                std::cout << "\n";
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] series[i];
    }
    delete[] series;

    return 0;
}


