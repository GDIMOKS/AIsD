#include <vector>
#include <queue>
#include "iostream"



class Node {
public:

    std::vector<int> children;
    bool isVisited;
    std::string color;
    int parent;

    Node() {
        isVisited = false;
        color = "white";
        parent = -1;
    }
};

class Graph {
// BFS, DFS
// МАТРИЦА СМЕЖНОСТИ N*N
// СПИСОК СМЕЖНОСТИ
// МАТРИЦА ИНЦИДЕНТНОСТИ (СТОЛБЦЫ - ВЕРШИНЫ, СТРОКИ - РЕБРА)

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

    bool DFS(int current) {
        nodes[current]->color = "grey";

        for (auto & child : nodes[current]->children){

            if (nodes[child]->color == "white") {
                nodes[child]->parent = current;

                if (DFS(child))
                    return true;
            } else if (nodes[child]->color == "grey" && child != nodes[current]->parent)
                return true;
        }

        nodes[current]->color = "black";

        return false;
    }

    bool BFS(int startNode, int goalNode) {
        std::queue<int> queue;

        for (int i = 0; i < nodes.size(); i++) {
            nodes[i]->isVisited = false;
        }

        queue.push(startNode);
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            if (currentNode == goalNode)
                return true;
            nodes[currentNode]->isVisited = true;

            for (auto& child : nodes[currentNode]->children) {
                if (!nodes[child]->isVisited) {
                    queue.push(child);
                    nodes[child]->isVisited = true;
                }
            }
        }

        return false;
    }

    void Print() {
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

        if (u == v)
            continue;
        graph->nodes[u-1]->children.push_back(v-1);
        graph->nodes[v-1]->children.push_back(u-1);
    }

    bool hasCycle = false;

    for (int i = 0; i < N; i++) {
        if (!graph->nodes[i]->isVisited)
            if (graph->DFS(i)) {
                hasCycle = true;
                break;
            }
    }

    if (hasCycle)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";


    delete graph;
}