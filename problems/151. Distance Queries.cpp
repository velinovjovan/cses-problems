#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> path;

void dfs(vector<vector<int>> &adj, int node, int prev){

	for(auto &x : adj[node]){
		if(x != prev){
			path[x] = path[node] + 1;
			parent[x] = node;
			dfs(adj, x, node);			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>> adj (n + 1);
	
	for(int i = 1 ; i <= n - 1 ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parent.resize(n + 1);
	path.resize(n + 1);
	
	dfs(adj, 1, 0);
	
	int size = 0;
	int temp = n;
	while(temp){
		size ++;
		temp >>= 1;
	}
	
	vector<vector<int>> sparse (size, vector<int> (n + 1));
	
	for(int i = 0 ; i < size ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(i == 0){
				sparse[i][j] = parent[j];
			}
			else{
				sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
			}
		}
	}
	
	
	while(q--){
		int a, b;
		cin >> a >> b;
		
		int copya = a;
		int copyb = b;
		
		if(path[a] < path[b]){
			swap(a, b);
		}
		
		int diff = path[a] - path[b];
		
		int i = 0;
		while(diff){
			if(diff & 1){
				a = sparse[i][a];
			}
			++i;
			diff >>= 1;
		}
		
		int lca;
		
		if(a == b){
			lca = a;
		}
		else{
			for(int i = size - 1 ; i >= 0 ; --i){
				if(sparse[i][a] != sparse[i][b]){
					a = sparse[i][a];
					b = sparse[i][b];
				}
			}
			lca = parent[a];
		}
		
		cout << path[copya] + path[copyb] - 2 * path[lca] << "\n";
	}
	
	
	return 0;
}
