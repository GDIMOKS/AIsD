#include <iostream>
#include <vector>

#define N_MAX 100
#define M_MAX 100


/*class Node {
public:
    std::vector<int> children;

    Node() {
        children = std::vector<int>();
    }
    Node(int size) {
        children = std::vector<int>(size);
    }
};*/

class Graph {
public:
    std::vector<int> nodes[N_MAX * M_MAX];



    bool dfs(int source, std::vector<bool> & visited, std::vector<int> & covered) {

        if (visited[source])
            return false;

        visited[source] = true;

        for (auto & child : nodes[source]) {
            if (covered[child] == -1 || dfs(covered[child], visited, covered)) {
                covered[child] = source;
                return true;
            }
        }

        return false;
    }

    int maxCovered(int n, int m) {
        std::vector<bool> visited;
        std::vector<int> covered(n*m, -1);
        int result = 0;

        for (int i = 0; i < n * m; i++) {
            visited.assign(n * m, false);
            if (dfs(i, visited, covered)) {
                result++;
            }
        }

        return result;
    }

};



int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Q;
    std::cin >> N >> M >> Q;

    Graph * graph = new Graph();
    std::vector<std::vector<bool>> crossedOut(N, std::vector<bool>(M, false));

    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        crossedOut[x][y] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (crossedOut[i][j]) continue;

            if (i - 1 >= 0 && !crossedOut[i - 1][j]) {
                graph->nodes[i * M + j].push_back((i - 1) * M + j);
            }
            if (i + 1 < N && !crossedOut[i + 1][j]) {
                graph->nodes[i * M + j].push_back((i + 1) * M + j);
            }
            if (j - 1 >= 0 && !crossedOut[i][j - 1]) {
                graph->nodes[i * M + j].push_back(i * M + j - 1);
            }
            if (j + 1 < M && !crossedOut[i][j + 1]) {
                graph->nodes[i * M + j].push_back(i * M + j + 1);
            }
        }
    }

    std::cout << graph->maxCovered(N, M) << "\n";

    delete graph;

    return 0;
}