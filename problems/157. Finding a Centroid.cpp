#include<bits/stdc++.h>

using namespace std;

vector<int> ss_size;

void dfs(vector<vector<int>> &adj, int node, int prev){
    ss_size[node] = 1;
    
    for(auto &x : adj[node]){
    	if(x != prev){
    		dfs(adj, x, node);
    		ss_size[node] += ss_size[x];
		}
	}
}

int centroid(vector<vector<int>> &adj, int node, int prev, int n){
    for (auto &x : adj[node]) {
        if(x != prev){
        	if (ss_size[x] > n / 2) {
            	return centroid(adj, x, node, n);
        	}
		}
    }
    
    return node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> adj (n + 1);
    
    for (int i = 1 ; i <= n - 1 ; ++i){
    	int a, b;
    	cin >> a >> b;
    	
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    
    ss_size.resize(n + 1);
    
    dfs(adj, 1, 0);
    cout << centroid(adj, 1, 0, n) << "\n";
    
    return 0;
}
