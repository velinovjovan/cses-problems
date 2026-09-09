#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dist;

void dfs (int node, int prev){
	
	for(auto &x : adj[node]){
		if(x == prev) continue;
		dist[x] = dist[node] + 1;
		dfs(x, node);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	adj.resize(n + 1);
	dist.resize(n + 1);
	
	for(int i = 0 ; i < n - 1 ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dist[1] = 0;
	dfs(1, 0);
	
	int i = max_element(dist.begin(), dist.end()) - dist.begin();
	
	dist[i] = 0;
	dfs(i, 0);
	
	cout << *max_element(dist.begin(), dist.end()) << "\n";
	
	
	return 0;
}
