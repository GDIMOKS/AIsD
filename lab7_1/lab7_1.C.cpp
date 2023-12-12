#include <vector>
#include <queue>
#include "iostream"



class Node {
public:

    std::vector<int> children;
    bool isVisited;
    std::string color;

    Node() {
        isVisited = false;
        color = "white";

    }
};

class Graph {
public:
    std::vector<Node*> nodes;

    Graph() {

    }

    Graph(int size) {
        nodes = std::vector<Node *>(size);
        for (auto & node : nodes) {
            node = new Node();
        }
    }


    int bfs(int startNode, int goalNode) {
        std::queue<int> queue;
        std::vector<int> distances(nodes.size(), nodes.size());

        distances[startNode] = 0;


        queue.push(startNode);
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            for (auto& child : nodes[currentNode]->children) {
                if (distances[child] == nodes.size()) {
                    distances[child] = distances[currentNode]+1;
                    queue.push(child);
                }
            }
        }
        return (distances[goalNode] != nodes.size()) ? distances[goalNode] : -1;
    }

    void print() {
        for (int i = 0; i < nodes.size(); i++) {

            std::cout << i+1 << ": ";
            for (int j = 0; j < nodes[i]->children.size(); j++) {
                std::cout << nodes[i]->children[j]+1 << " ";
            }
            std::cout << "\n";
        }
    }

};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    Graph * graph = new Graph(N);

    for (int i = 0; i < M; i++) {
        int u, v;

        std::cin >> u >> v;

        graph->nodes[u-1]->children.push_back(v-1);
        graph->nodes[v-1]->children.push_back(u-1);
    }
    int S,F;
    std::cin >> S >> F;
    S--;
    F--;
    std::cout << graph->bfs(S,F);
    delete graph;

}