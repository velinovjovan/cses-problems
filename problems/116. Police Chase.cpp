#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int cap;
    int rev;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> adj(n + 1);
    vector<pair<int, int>> original_edges;

    auto add_edge = [&](int v, int u) {
        adj[v].push_back({u, 1, (int)adj[u].size()});
        adj[u].push_back({v, 1, (int)adj[v].size() - 1});
    };

    for (int i = 0; i < m; ++i) { 
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        original_edges.push_back({a, b});
    }

    int s = 1;
	int t = n;
    int flow = 0;

    while (true) {
        vector<pair<int, int>> parent(n + 1, {-1, -1});
        queue<int> red;

        red.push(s);
        parent[s] = {s, -1};

        while (!red.empty()) {
            int v = red.front();
            red.pop();

            if (v == t) break;

            for (int i = 0; i < (int)adj[v].size(); ++i) {
                auto &edge = adj[v][i];
                if (edge.cap > 0 && parent[edge.to].first == -1) {
                    parent[edge.to] = {v, i};
                    red.push(edge.to);
                }
            }
        }

        if (parent[t].first == -1) break;

        for (int v = t; v != s; v = parent[v].first) {
            int u = parent[v].first;
            int idx = parent[v].second;
            int idx_rev = adj[u][idx].rev;

            adj[u][idx].cap -= 1;
            adj[v][idx_rev].cap += 1;
        }

        flow += 1;
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto &edge : adj[v]) {
            if (edge.cap > 0 && !visited[edge.to]) {
                visited[edge.to] = true;
                q.push(edge.to);
            }
        }
    }

    cout << flow << "\n";
    for (auto &x : original_edges) {
    	int u, v;
    	tie(u, v) = x;
    	
        if ((visited[u] && !visited[v]) || (visited[v] && !visited[u])) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}
