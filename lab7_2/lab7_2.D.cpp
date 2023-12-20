#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include "iostream"

#define MAX 1e9


class Node {
public:
    int to;
    int weight;

};

class Graph {

public:
    std::vector<std::vector<Node>> nodes;

    Graph() {

    }

    Graph(int size) {
        nodes = std::vector<std::vector<Node>>(size);
    }

    int prim() {
        int n = nodes.size();
        std::vector<bool> visited(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;

        q.push({0, 0});
        int minDays = 0;

        while (!q.empty()) {
            Node node = {q.top().second, q.top().first};
            q.pop();

            if (visited[node.to]) continue;

            visited[node.to] = true;
            minDays += node.weight;

            for (auto& e : nodes[node.to]) {
                int v = e.to;
                int w = e.weight;
                if (!visited[v]) {
                    q.push({w, v});
                }
            }
        }

        return minDays;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    Graph * graph = new Graph(N);

    while (M--) {
        int start, end, weight;

        std::cin >> start >> end >> weight;
        start--;end--;

        graph->nodes[start].push_back({end, weight});
        graph->nodes[end].push_back({start, weight});


    }
    std::cout << graph->prim() << "\n";




    delete graph;
}