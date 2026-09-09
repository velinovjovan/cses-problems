#include<bits/stdc++.h>

using namespace std;

void dfs (int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &comp){
	visited[node] = true;
	
	for(auto &x : adj[node]){
		if(!visited[x]){
			dfs(x, adj, visited, comp);
		}
	}
	
	comp.push_back(node);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m; 
	
	vector<int> k (n + 1);
	
	for(int i = 1 ; i <= n ; ++i){
		cin >> k[i];
	}
	
	vector<vector<int>> adj (n + 1);
	vector<vector<int>> reverse_adj (n + 1);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		reverse_adj[b].push_back(a);
	}
	
	
	vector<bool> visited (n + 1, false);
	vector<int> outTime;
	
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			dfs(i, adj, visited, outTime);
		}
	}
	
	reverse(outTime.begin(), outTime.end());
	vector<vector<int>> components;
	
	fill(visited.begin(), visited.end(), false);
	
	vector<long long> coins;
	vector<int> sccID(n + 1);
	int ID = 0;	
		
	for(auto &node : outTime){
		if(!visited[node]){
			vector<int> curr_component;
			dfs(node, reverse_adj, visited, curr_component);
			
			long long temp = 0; 
			for(auto &x : curr_component){
				sccID[x] = ID;
				temp += k[x];
			}
			
			coins.push_back(temp);
			++ID;
		}
	}	
	
	vector<vector<int>> adj_dag(ID);
	
	for(int i = 1; i <= n; ++i){
		for(auto &x : adj[i]){
			if(sccID[x] != sccID[i]){
				adj_dag[sccID[i]].push_back(sccID[x]);
			}
		}
	}
	
	vector<long long> dp(ID, 0);

	for(int i = ID - 1; i >= 0; --i){
		
		long long temp = 0;
		for(auto &x : adj_dag[i]){
			temp = max(temp, dp[x]);
		}
		
		dp[i] = coins[i] + temp;
	}
	
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	
	return 0;
}
