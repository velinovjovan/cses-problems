#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int node, int prev, vector<int> &dist){
	
	for(auto &x : adj[node]){
		if(x != prev){
			dist[x] = dist[node] + 1;
			dfs(adj, x, node, dist);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> adj (n + 1);
	
	for(int i = 2 ; i <= n ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> dist (n + 1, numeric_limits<int>::min());
	dist[1] = 0;
	dfs(adj, 1, 0, dist);
	
	vector<int> dist1 (n + 1, numeric_limits<int>::min());
	dist1[max_element(dist.begin(), dist.end()) - dist.begin()] = 0;
	dfs(adj, max_element(dist.begin(), dist.end()) - dist.begin(), 0, dist1);
	
	vector<int> dist2 (n + 1, numeric_limits<int>::min());
	dist2[max_element(dist1.begin(), dist1.end()) - dist1.begin()] = 0;
	dfs(adj, max_element(dist1.begin(), dist1.end()) - dist1.begin(), 0, dist2);
	
	
	for(int i = 1 ; i <= n ; ++i){
		cout << max(dist1[i], dist2[i]) << ' ';
	}
	cout << "\n";
	
	
	return 0;
}
