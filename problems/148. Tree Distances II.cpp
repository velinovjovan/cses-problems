#include<bits/stdc++.h>

using namespace std;

vector<int> parent;

void dfs(vector<vector<int>> &adj, int node, int prev, vector<int> &ss_size, vector<long long> &cost){
	
	cost[node] = 0;
	ss_size[node] = 1;
	for(auto &x : adj[node]){
		if(x != prev){
			dfs(adj, x, node, ss_size, cost);
			ss_size[node] += ss_size[x];
			cost[node] += cost[x] + ss_size[x];
		}
	}
}

void dfs2(vector<vector<int>> &adj, int node, int prev, vector<int> &ss_size, vector<long long> &cost, int n){
	
	for(auto &x : adj[node]){
		if(x != prev){
			cost[x] = cost[node] - ss_size[x] + (n - ss_size[x]);
			dfs2(adj, x, node, ss_size, cost, n);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> adj (n + 1);
	
	for(int i = 1 ; i <= n - 1 ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> ss_size (n + 1);
	vector<long long> cost (n + 1);
	parent.resize(n + 1);
	
	dfs(adj, 1, 0, ss_size, cost);
	dfs2(adj, 1, 0, ss_size, cost, n);
	
	for(int i = 1 ; i < cost.size() ; ++i){
		cout << cost[i] << ' ';
	}
	cout << "\n";
	
	return 0;
}
