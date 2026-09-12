#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> matched;
int ans = 0;

void dfs(int node, int prev) {
    
	for(int &x : adj[node]) {
        if(x != prev) {
            dfs(x, node);

            if(!matched[node] && !matched[x]) {
                matched[node] = true;
                matched[x] = true;
                ans++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    matched.assign(n + 1, false);
    
    for(int i = 1 ; i <= n - 1 ; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    
    cout << ans << "\n";
    
    return 0;
}
