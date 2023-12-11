#include <vector>
#include <queue>
#include "iostream"
/*
class Data {
public:
    int value;
};*/

class Node {
public:
/*
    Data * data;
*/
    std::vector<int> children;
    bool isVisited;

    Node() {
        isVisited = false;
/*
        children = std::vector<int>();
*/
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

    bool DFS() {

    }

    bool BFS(int startNode, int goalNode) {
        std::queue<int> queue;

/*        for (int i = 0; i < nodes.size(); i++) {
            visited[i] = false;
        }*/

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
/*            if (nodes[i]->children.empty())
                continue;*/

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

    graph->Print();

    /*if (graph->BFS(0,0))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";*/

    delete graph;
}