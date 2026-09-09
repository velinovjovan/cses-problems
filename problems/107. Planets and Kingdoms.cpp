#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &pass) {
    visited[node] = true; 
    
    for (auto &x : adj[node]) {
        if (!visited[x]) {
            dfs(x, adj, visited, pass);
        }
    }
    pass.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    vector<int> fowardPass;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, fowardPass);
        }
    }
    
    reverse(fowardPass.begin(), fowardPass.end());
    
    fill(visited.begin(), visited.end(), false); 
    vector<vector<int>> kingdoms;

    for (auto node : fowardPass) {
        if (!visited[node]) {
            kingdoms.push_back(vector<int>());
            dfs(node, rev_adj, visited, kingdoms.back()); 
        }
    }
    
    vector<int> ans(n + 1);
    int id = 1;
    
    for (auto &kingdom : kingdoms) {
        for (auto &node : kingdom) {
            ans[node] = id;
        }
        ++id;
    }
    
    cout << id - 1 << "\n";
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
