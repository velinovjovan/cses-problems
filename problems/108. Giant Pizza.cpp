#include <bits/stdc++.h>

using namespace std;

void dfs1(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &pass) {
    visited[node] = true;
    for (int x : adj[node]) {
        if (!visited[x]) {
            dfs1(x, adj, visited, pass);
        }
    }
    pass.push_back(node);
}

void dfs2(int node, const vector<vector<int>> &rev_adj, vector<int> &comp, int current_comp) {
    comp[node] = current_comp;
    for (int x : rev_adj[node]) {
        if (comp[x] == 0) {
            dfs2(x, rev_adj, comp, current_comp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(m * 2 + 1);
    vector<vector<int>> rev_adj(m * 2 + 1);
    
    auto neg = [&](int x) {
        return x > m ? x - m : x + m;
    };
    
    for (int i = 0; i < n; ++i) {
        char sign1, sign2;
        int u, v;
        cin >> sign1 >> u >> sign2 >> v;
        
        if (sign1 == '-') u += m;
        if (sign2 == '-') v += m;
        
        adj[neg(u)].push_back(v);
        adj[neg(v)].push_back(u);
        
        rev_adj[v].push_back(neg(u));
        rev_adj[u].push_back(neg(v));
    }    
    
    vector<bool> visited(m * 2 + 1, false);
    vector<int> fowardPass;
    
    for (int i = 1; i <= m * 2; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, fowardPass);
        }
    }
    
    vector<int> comp(m * 2 + 1, 0);
    int current_comp = 1;
    
    for (int i = m * 2 - 1; i >= 0; --i) {
        int node = fowardPass[i];
        if (comp[node] == 0) {
            dfs2(node, rev_adj, comp, current_comp);
            current_comp++;
        }
    }

    string ans = "";
    
    for (int i = 1; i <= m; ++i) {
        if (comp[i] == comp[i + m]) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
        
        if (comp[i] > comp[i + m]) {
            ans += "+ ";
        } 
		else {
            ans += "- ";
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
