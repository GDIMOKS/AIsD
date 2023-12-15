#include "iostream"
#include "vector"
#include "stack"

class Node {
public:
    std::vector<int> children;
};

class Graph {
public:
    std::vector<Node> nodes;

    Graph(int size) {
        nodes = std::vector<Node>(size);

    }

    bool dfs(int start) {
        std::stack<int> stack;
        std::vector<bool> visited(nodes.size());

        int visitedCount = 0;
        stack.push(start);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            if (visited[current]) continue;

            visited[current] = true;
            visitedCount++;

            if (visitedCount == nodes.size()) return true;

            for (auto & child : nodes[current].children)
                if (!visited[child])
                    stack.push(child);

        }

        return false;
    }


    bool checkHamiltonWay() {
        int source = -1;
        int counter = 0;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].children.size() == 1) {
                counter++;
                source = i;
            }
            if (counter > 2)
                return false;
        }

        if (source == -1)
            source = 0;

        return dfs(source);
    }

};

int main() {
    int n, m;

    std::cin >> n >> m;

    Graph * graph = new Graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;

        std::cin >> u >> v;
        u--;v--;

        graph->nodes[u].children.push_back(v);
        graph->nodes[v].children.push_back(u);
    }

    if (graph->checkHamiltonWay())
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    delete graph;
    return 0;
}
