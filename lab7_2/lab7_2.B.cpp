/*
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

    int N, M, S, T;
    std::cin >> N >> M >> S >> T;

    S--; T--;
    Graph * graph = new Graph(N);

    while (M--) {
        int start, end, weight;

        std::cin >> start >> end >> weight;
        start--;end--;

        graph->nodes[start].push_back({end, weight});


    }

    std::vector dist = graph->dijkstra(S);


    if (dist[T] != MAX) {
        std::cout << dist[T] << "\n";
    } else {
        std::cout << -1 << "\n";
    }



    delete graph;
}*/
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

    void dfs(int source, std::vector<bool> & visited, std::vector<int> & sortedGraph) {

        visited[source] = true;


        for (auto & child : nodes[source])
            if (!visited[child.to])
                dfs(child.to, visited, sortedGraph);

        sortedGraph.push_back(source);
    }

    std::vector<int> dag(int source) {
        std::vector<bool> visited(nodes.size());
        std::vector<int> sortedGraph;

        for (int i = 0; i < nodes.size(); i++) {
            if (!visited[i])
                dfs(source, visited, sortedGraph);
        }

        std::reverse(sortedGraph.begin(), sortedGraph.end());

        std::vector<int> dist(nodes.size(), MAX);
        dist[source] = 0;
        for (int v : sortedGraph) {
            for (auto & node : nodes[v]) {
                if (dist[v] != MAX && dist[node.to] > dist[v] + node.weight)
                    dist[node.to] = dist[v] + node.weight;
            }
        }

        return dist;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, S, T;
    std::cin >> N >> M >> S >> T;

    S--; T--;
    Graph * graph = new Graph(N);

    while (M--) {
        int start, end, weight;

        std::cin >> start >> end >> weight;
        start--;end--;

        graph->nodes[start].push_back({end, weight});


    }

    std::vector dist = graph->dag(S);


    if (dist[T] != MAX) {
        std::cout << dist[T] << "\n";
    } else {
        std::cout << -1 << "\n";
    }



    delete graph;
}