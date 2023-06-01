#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // initialize the initial distance to infinity

// function for dijkstra's algorithm
void dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF); // initialize all distances as infinity
    dist[source] = 0; // distance from source to source is 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // a min-heap to store nodes with shortest distance
    pq.push(make_pair(dist[source], source)); // push source node into the heap

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if (d <= dist[u]) { // if this is a shorter path to u, update distance and add to queue
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    // print the shortest distance from source to each vertex
    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int n = 5; // number of vertices
    vector<vector<int>> graph(n, vector<int>(n, 0)); // initialize graph with all 0's

    // add edges to the graph
    graph[0][1] = 10;
    graph[0][3] = 5;
    graph[1][2] = 1;
    graph[1][3] = 2;
    graph[2][4] = 4;
    graph[3][1] = 3;
    graph[3][2] = 9;
    graph[3][4] = 2;

    dijkstra(graph, 0);

    return 0;
}
