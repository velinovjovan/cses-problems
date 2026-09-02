#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, numeric_limits<long long>::max());
    vector<long long> ways(n + 1, 0);
    vector<int> min_f(n + 1, 0);
    vector<int> max_f(n + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    ways[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
    	long long d;
    	int u;
    	
        tie(d, u) = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &x : adj[u]) {
    		int v;
    		long long w;
    		tie(v, w) = x;
    
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;
                pq.push({dist[v], v});
            } 
            else if (dist[u] + w == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                min_f[v] = min(min_f[v], min_f[u] + 1);
                max_f[v] = max(max_f[v], max_f[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << min_f[n] << " " << max_f[n] << "\n";
}
