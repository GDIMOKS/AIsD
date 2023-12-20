#include <vector>
#include "iostream"

#define MAX 49500000

class Node {
public:

    std::vector<int> children;
    std::vector<int> distances;

    Node() {
        children = std::vector<int>();
    }
    Node(int size) : Node() {
        distances = std::vector<int>(size, MAX);
    }
};


class Graph {
public:
    std::vector<Node*> nodes;

    int maxDist;

    Graph() {
        maxDist = 0;
    }

    Graph(int size) : Graph(){
        nodes = std::vector<Node *>(size);
        for (auto & node : nodes) {
            node = new Node(size);
        }
    }

    void floydWarshall() {
        int n = nodes.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (nodes[i]->distances[k] < MAX && nodes[k]->distances[j] < MAX) {
                        nodes[i]->distances[j] = std::min(nodes[i]->distances[j], nodes[i]->distances[k] + nodes[k]->distances[j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nodes[i]->distances[j] != MAX) {
                    maxDist = std::max(maxDist, nodes[i]->distances[j]);
                }
            }
        }
    }




};



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Graph * graph = new Graph(n);

    for (int i = 0; i < m; i++) {
        int s, e, l;
        std::cin >> s >> e >> l;
        s--;
        e--;

        graph->nodes[s]->children.push_back(e);
        graph->nodes[s]->distances[s] = 0;
        graph->nodes[s]->distances[e] = l;

        graph->nodes[e]->children.push_back(s);
        graph->nodes[e]->distances[e] = 0;
        graph->nodes[e]->distances[s] = l;

    }


    graph->floydWarshall();

    if (graph->maxDist == 0)
        std::cout << 0 << "\n";
    else
        std::cout << graph->maxDist << "\n";

    delete graph;

}
