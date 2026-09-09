#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    long long cap;
    int rev;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    auto add_edge = [&](int u, int v, long long cap) {
        adj[u].push_back({v, cap, (int)adj[v].size()});
        adj[v].push_back({u, 0, (int)adj[u].size() - 1});
    };

    for (int i = 0 ; i < m ; ++i) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        
        add_edge(u, v, cap);
    }

    int s = 1;
	int t = n;
    long long max_flow = 0;

    while (true) {
        vector<pair<int, int>> parent(n + 1, {-1, -1});
        queue<int> q;

        q.push(s);
        parent[s] = {s, -1};

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == t) break;

            for (int i = 0; i < (int)adj[u].size() ; ++i) {
                const auto &edge = adj[u][i];
                
                if (edge.cap > 0 && parent[edge.to].first == -1) {
                    parent[edge.to] = {u, i};
                    q.push(edge.to);
                }
            }
        }

        if (parent[t].first == -1) break;

        long long bottleneck = 1e18;
        for (int v = t ; v != s ; v = parent[v].first) {
            int u = parent[v].first;
            int idx = parent[v].second;
            bottleneck = min(bottleneck, adj[u][idx].cap);
        }

        for (int v = t ; v != s ; v = parent[v].first) {
            int u = parent[v].first;
            int idx = parent[v].second;
            int rev_idx = adj[u][idx].rev;

            adj[u][idx].cap -= bottleneck;
            adj[v][rev_idx].cap += bottleneck;
        }

        max_flow += bottleneck;
    }

    cout << max_flow << "\n";

    return 0;
}
