#include<bits/stdc++.h>

using namespace std;

vector<int> parent_node;
vector<int> depth;
vector<int> ans;

void dfs_parent(vector<vector<int>> &adj, int node, int prev){
	for(auto &x : adj[node]){
		if(x != prev){
			parent_node[x] = node;
			depth[x] = depth[node] + 1;
			dfs_parent(adj, x, node);
		}
	}
}

void dfs_after(vector<vector<int>> &adj, int node, int prev){
	for(auto &x : adj[node]){
		if(x != prev){
			dfs_after(adj, x, node);
			ans[node] += ans[x]; 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj (n + 1);
	
	for(int i = 1 ; i <= n - 1 ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parent_node.resize(n + 1, 0);
	depth.resize(n + 1, 0);
	ans.resize(n + 1, 0);
	
	dfs_parent(adj, 1, 0);
	
	int size = 0;
	int temp = n;
	while(temp){
		size ++;
		temp >>= 1;
	}
	
	vector<vector<int>> sparse (size, vector<int> (n + 1, 0));
	
	for(int i = 0 ; i < size ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(i == 0){
				sparse[i][j] = parent_node[j];
			}
			else{
				sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
			}
		}
	}
	
	while(m--){
		int a, b;
		cin >> a >> b;
		
		int copya = a;
		int copyb = b;
		
		if(depth[a] < depth[b]){
			swap(a, b);
		}
		
		int diff = depth[a] - depth[b];
		
		int i = 0;
		while(diff){
			if(diff & 1){
				a = sparse[i][a];
			}
			++i;
			diff >>= 1;
		}
		
		int lca;
		
		if (a == b) {
		    lca = a;
		} 
		else{
    		for(int i = size - 1 ; i >= 0 ; --i){
    			if(sparse[i][a] != sparse[i][b]){
    				a = sparse[i][a];
    				b = sparse[i][b];
    			}
    		}
    		lca = parent_node[a];
		}
		
		ans[copya] ++;
		ans[copyb] ++;
		ans[lca] --;
		ans[parent_node[lca]] --;
	}
	
	dfs_after(adj, 1, 0);
	
	for(int i = 1 ; i <= n ; ++i){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
