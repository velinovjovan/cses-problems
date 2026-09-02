#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    vector<int> ngl(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ngl[i] = st.top();
        }
        st.push(i);
    }
    
    vector<int> ngr(n, -1);
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ngr[i] = st.top();
        }
        st.push(i);
    }
 
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (ngl[i] != -1) {
            adj[ngl[i]].push_back(i);
            indegree[i]++;
        }
        if (ngr[i] != -1) {
            adj[ngr[i]].push_back(i);
            indegree[i]++;
        }
    }

    vector<int> dp(n, 1);
    queue<int> q;
    
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int max_visited = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        max_visited = max(max_visited, dp[u]);
        
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << max_visited << "\n";
    
    return 0;
}
