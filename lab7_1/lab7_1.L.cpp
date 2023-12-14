#include <vector>
#include <algorithm>
#include <stack>
#include "iostream"

#define MAX 1e9


class Node {
public:
    int start, end, weight;

    Node() {
        start = end = weight = 0;
    }
    Node(int _start, int _end,int _weight) {
        start = _start;
        end = _end;
        weight = _weight;
    }
};

class Graph {

public:
    std::vector<Node> nodes;

    Graph() {

    }

    Graph(int size) {
        nodes = std::vector<Node>(size, Node());
    }


    bool checkGraph() {
        std::vector<int> distances(nodes.size(), MAX);
        distances[0] = 0;

        bool hasChanges;

        for (int i = 0; i < nodes.size(); i++) {
            hasChanges = false;
            for (auto & node : nodes) {
                if (distances[node.start] < MAX && distances[node.start] + node.weight < distances[node.end]) {
                    distances[node.end] = distances[node.start] + node.weight;
                    hasChanges = true;
                }
            }

            if (!hasChanges)
                break;
        }
        return hasChanges;
    }


};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, k, n, m;
    std::cin >> N >> k;

    while (N--) {
        std::cin >> n >> m;
        Graph * graph = new Graph(n);

        for (int i = 0; i < m; i++) {
            int start, end, w;

            std::cin >> start >> end >> w;
            start--;
            end--;

            graph->nodes.push_back(Node(start, end, w));
        }

        if (!graph->checkGraph() || graph->nodes.size() < k)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";


        delete graph;
    }

}
