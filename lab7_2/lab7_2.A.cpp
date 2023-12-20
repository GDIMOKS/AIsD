#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include "iostream"

#define MAX 1e9


class Node {
public:
    int to;
    int weight;

};

class Graph {

public:
    std::vector<std::vector<Node>> nodes;

    Graph() {

    }

    Graph(int size) {
        nodes = std::vector<std::vector<Node>>(size);
    }


    std::vector<int> dijkstra(int source) {
        std::vector<int> dist(nodes.size(), MAX);

        dist[source] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<> >q ;

        q.push({dist[source], source});

        while (!q.empty()) {
            auto [nearestDist, nearest] = q.top();
            q.pop();

            if (nearestDist != dist[nearest]) continue;

            for (auto & node : nodes[nearest]) {
                if (dist[node.to] > dist[nearest] + node.weight) {
                    dist[node.to] = dist[nearest] + node.weight;
                    q.push({dist[node.to], node.to});
                }
            }
        }

        return dist;
    }

};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Q, Start;
    std::cin >> N >> M >> Q >> Start;

    Start--;
    Graph * graph = new Graph(N);

    while (M--) {
        int start, end, weight;

        std::cin >> start >> end >> weight;
        start--;
        end--;

        graph->nodes[start].push_back({end, weight});
        graph->nodes[end].push_back({start, weight});


    }

    std::vector dist = graph->dijkstra(Start);

    while (Q--) {
        int value;
        std::cin >> value;
        value--;
        if (dist[value] != MAX) {
            std::cout << dist[value] << "\n";
        } else {
            std::cout << -1 << "\n";
        }

    }


    delete graph;
}