#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> ans;

void dfs(int node) {
    for (int child : adj[node]) {
        dfs(child);
        ans[node] += ans[child] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    ans.assign(n + 1, 0);
    
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    
    dfs(1);
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
