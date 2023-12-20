#include <vector>
#include <algorithm>
#include "iostream"



class Node {
public:

    std::vector<int> children;
    std::string color;
    int parent;

    Node() {
        color = "white";
        parent = -1;
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

    std::vector<int> getCycle(int last) {
        std::vector<int> cycle = {last};
        for (int i = nodes[last]->parent; i != last; i = nodes[i]->parent) {
            cycle.push_back(i);
        }
        std::reverse(cycle.begin(), cycle.end());
        return cycle;
    }

    void dfs(int current, std::vector<int> &cycle) {
        nodes[current]->color = "grey";

        for (auto & child : nodes[current]->children){

            if (nodes[child]->color == "white") {
                nodes[child]->parent = current;

                dfs(child, cycle);
                if (!cycle.empty())
                    return;
            } else if (nodes[child]->color == "grey") {
                nodes[child]->parent = current;
                cycle = getCycle(child);
                return;
            }
        }

        nodes[current]->color = "black";

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

    int N, M, Q;
    std::cin >> N >> M >> Q;
    Graph * graph = new Graph(N);

    for (int i = 0; i < M; i++) {
        int u, v;

        std::cin >> u >> v;

        graph->nodes[u-1]->children.push_back(v-1);

    }

    while (Q--) {
        int A,B;
        std::cin >> A >> B;

        std::vector<int> cycle;
        A--;
        B--;
        graph->dfs(A, cycle);
        if (std::find(cycle.begin(), cycle.end(), B) != cycle.end())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    delete graph;

}