#include <vector>
#include <algorithm>
#include <stack>
#include "iostream"

class Node {
public:
    std::vector<int> children;
};

class Graph {

public:
    std::vector<Node> nodes;

    Graph() {

    }

    Graph(int size) {
        nodes = std::vector<Node>(size, Node());
    }


    std::stack<int> topologicalSort() {
        auto sortedGraph = std::stack<int>();
        auto visited = std::vector<bool>(nodes.size(), false);

        for (int i = 0; i < nodes.size(); i++) {
            if (!visited[i]) {
                dfs(i, visited, sortedGraph);
            }
        }

        return sortedGraph;
    }

    void dfs(int source, std::vector<bool> & visited, std::stack<int> & sortedGraph) {

        visited[source] = true;


        for (int & child : nodes[source].children)
            if (!visited[child])
                dfs(child, visited, sortedGraph);

        sortedGraph.push(source);
    }




    void print() {
        for (int i = 0; i < nodes.size(); i++) {

            std::cout << i+1 << ": ";
            for (int j = 0; j < nodes[i].children.size(); j++) {
                std::cout << nodes[i].children[j]+1 << " ";
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
        int u, v;

        std::cin >> u >> v;

        graph->nodes[u-1].children.push_back(v-1);

    }

    std::stack<int> sortedGraph = graph->topologicalSort();

    std::vector<int> newNames(n);

    int count = 0;
    while (!sortedGraph.empty()) {
        newNames[sortedGraph.top()] = count++;
        sortedGraph.pop();
    }

    for (int i = 0; i < n; ++i) {
        std::cout << newNames[i]+1 << " ";
    }

    delete graph;
}
