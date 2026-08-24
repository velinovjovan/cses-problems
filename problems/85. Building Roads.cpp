#include <bits/stdc++.h>

using namespace std;

bool visited[100005];
vector<int> adj[100005];
 
void dfs (int node) {
    if (visited[node]) return;
    
    visited[node] = true;
    
    for (auto neighbor : adj[node]) dfs(neighbor);
}
 
int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1);
    vector<pair<int, int>> ans;
 
    for (int i = 1 ; i <= n ; ++i) {
        if (!visited[i]) {
            adj[1].push_back(i);
            adj[i].push_back(1);
            ans.push_back({1, i});
            dfs(i);
        }
    }
 
    cout << ans.size() << "\n";
    for (auto &x : ans){
        cout << x.first << ' ' << x.second << "\n";
	}
	
	return 0;
}
