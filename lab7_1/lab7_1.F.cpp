#include <vector>
#include <queue>
#include "iostream"



class Node {
public:

    std::vector<int> children;
    bool isVisited;
    std::string color;
    int parent;
    int component;
    int status;

    Node() {
        isVisited = false;
        color = "white";
        parent = -1;
        component = 0;
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

    bool dfs(int current) {
        nodes[current]->color = "grey";

        for (auto & child : nodes[current]->children){

            if (nodes[child]->color == "white") {
                nodes[child]->parent = current;

                if (dfs(child))
                    return true;
            } else if (nodes[child]->color == "grey" && child != nodes[current]->parent)
                return true;
        }

        nodes[current]->color = "black";

        return false;
    }

    int dfs() {
        for (auto & node : nodes) {
            node->color = "white";
            node->component = 0;
        }

        int count = 0;

        for (auto & node : nodes) {
            if (node->color == "white") {
                visit(node, count);
                count++;

            }
        }
        return count;
    }

    void visit(Node * node, int &count) {
        node->color = "grey";
        node->component = count;

        for (auto & child : node->children) {
            if (nodes[child]->color == "white") {
                visit(nodes[child], count);
            }
        }

        node->color = "black";
    }

    bool bfs(int startNode, int goalNode) {
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

    int n, m;
    std::cin >> n >> m;

    Graph * graph = new Graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;

        graph->nodes[a]->children.push_back(b);
        graph->nodes[b]->children.push_back(a);

    }

    for (int i = 0; i < n; i++) {
        int status;
        std::cin >> status;
        graph->nodes[i]->status = status;
    }

    int count = graph->dfs();
    std::cout << count << "\n";

    std::vector<int> components(count, 0);

    for (auto & node : graph->nodes) {
        std::cout << node->component+1 << " ";
        if (components[node->component] == 0 && node->status == 1)
            components[node->component] = 1;
    }

    std::cout << "\n";

    for (auto & danger : components)
        std::cout << danger << " ";

    delete graph;

}