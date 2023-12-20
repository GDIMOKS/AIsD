#include <vector>
#include <queue>
#include "iostream"
#include <algorithm>


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

    int n, m, q;
    std::cin >> n >> m >> q;
    Graph * graph = new Graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;

        std::cin >> u >> v;

        graph->nodes[u-1]->children.push_back(v-1);
        graph->nodes[v-1]->children.push_back(u-1);
    }

    while (q--) {
        int a,b;
        char command;
        std::cin >> command >> a >> b;

        switch (command) {
            case '?':
                a--;
                b--;
                if (graph->bfs(a, b)) {
                    std::cout << "YES\n";
                } else {
                    std::cout << "NO\n";
                }
                break;
            case '-':
                a--;
                b--;
                auto &bChilds = graph->nodes[b]->children;
                auto &aChilds = graph->nodes[a]->children;

                auto aIterator = std::find(bChilds.begin(), bChilds.end(), a);
                auto bIterator = std::find(aChilds.begin(), aChilds.end(), b);

                aChilds.erase(bIterator);
                bChilds.erase(aIterator);

                break;
        }
    }
    delete graph;

}