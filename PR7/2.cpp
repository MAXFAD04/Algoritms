#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // initialize the initial flow to infinity

struct Edge {
    int v, u, cap, flow;
    Edge(int v, int u, int cap) : v(v), u(u), cap(cap), flow(0) {}
};

int n, m, s, t; // number of nodes, number of edges, source node, sink node
vector<vector<int>> adj; // adjacency list to store edges
vector<Edge> edges; // vector to store edges

void addEdge(int v, int u, int cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(edges.size() - 2);
    adj[u].push_back(edges.size() - 1);
}

bool bfs(vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({ s, INF });

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int e : adj[u]) {
            int v = edges[e].u;
            if (parent[v] == -1 && edges[e].cap - edges[e].flow > 0) {
                parent[v] = e;
                int new_flow = min(flow, edges[e].cap - edges[e].flow);
                if (v == t) {
                    return new_flow;
                }
                q.push({ v, new_flow });
            }
        }
    }
    return 0;
}

int maxFlow() {
    int flow = 0;
    vector<int> parent(m);
    int new_flow;

    while (new_flow = bfs(parent)) {
        flow += new_flow;
        int u = t;
        while (u != s) {
            int e = parent[u];
            edges[e].flow += new_flow;
            edges[e ^ 1].flow -= new_flow;
            u = edges[e].v;
        }
    }

    return flow;
}

int main() {
    cin >> n >> m >> s >> t;

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int v, u, cap;
        cin >> v >> u >> cap;
        addEdge(v - 1, u - 1, cap); // subtract 1 to adjust node numbering to start from 0
    }

    cout << "Maximum flow: " << maxFlow() << endl;

    return 0;
