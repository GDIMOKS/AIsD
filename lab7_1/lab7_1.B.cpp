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

class Pair {
public:
    Pair() {
        value = -1;
    }
    Pair(char sign) {

    }

    char sign;
    int value;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    auto apartment = std::vector<std::vector<Pair>>(n);
    Graph * graph = new Graph();

    int k = 0;
    for (int i = 0; i < n; i ++) {
        apartment[i] = std::vector<Pair>(m);

        for (int j = 0; j < m; j++) {
            char sign;
            std::cin >> sign;
            apartment[i][j].sign = sign;


            if (sign == '.') {
                apartment[i][j].value = k;

                graph->nodes.push_back(new Node());

                if (j-1 >= 0 && apartment[i][j-1].sign == '.') {
                    int left = apartment[i][j-1].value;
                    graph->nodes[k]->children.push_back(left);
                    graph->nodes[left]->children.push_back(k);
                }
                if (i-1 >= 0 && apartment[i-1][j].sign == '.') {
                    int up = apartment[i-1][j].value;
                    graph->nodes[up]->children.push_back(k);
                    graph->nodes[k]->children.push_back(up);
                }
                k++;

            }
        }
    }
    std::cout << graph->dfs() << "\n";
    delete graph;

}