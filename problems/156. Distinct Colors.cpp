#include<bits/stdc++.h>

using namespace std;

vector<int> color;
vector<int> ans;
vector<set<int>> stek;

void dfs(vector<vector<int>> &adj, int node, int prev){
    stek[node].insert(color[node]);
    
    for (int &x : adj[node]) {
        if(x != prev){
        	dfs(adj, x, node);
        	
        	if(stek[node].size() < stek[x].size()) swap(stek[node], stek[x]);
        	for(auto &color : stek[x]) stek[node].insert(color);
		}
    }
    
    ans[node] = stek[node].size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    color.resize(n + 1);
    stek.resize(n + 1);
    ans.resize(n + 1);
    
    for (int i = 1 ; i <= n ; ++i){
        cin >> color[i];
    }
    
    vector<vector<int>> adj (n + 1);
    
    for (int i = 1 ; i <= n - 1 ; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj, 1, 0);
    
    for (int i = 1 ; i <= n ; ++i){
        cout << ans[i] << ' ';
    }
    cout << "\n";
    
    
    return 0;

}
