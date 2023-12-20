#include <vector>
#include <algorithm>
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


    bool checkPath(int source, int destination) {
        auto visited = std::vector<bool>(nodes.size(), false);

        return dfs(source,destination, visited);
    }

    bool dfs(int source, int destination, std::vector<bool> & visited) {
        if (source == destination)
            return true;

        visited[source] = true;


        for (int child : nodes[source].children){
            if (!visited[child]) {
                if (dfs(child, destination, visited))
                    return true;
            }
        }

        return false;
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

    int N, M, Q;
    std::cin >> N >> M >> Q;
    Graph * graph = new Graph(N);

    for (int i = 0; i < M; i++) {
        int u, v;

        std::cin >> u >> v;

        graph->nodes[u-1].children.push_back(v-1);

    }

    while (Q--) {
        int A,B;
        std::cin >> A >> B;

        A--;
        B--;

        if (graph->checkPath(A, B) && graph->checkPath(B,A))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    delete graph;

}