#include<bits/stdc++.h>

using namespace std;

struct Edge{
	int to;
	int cap;
	int rev;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<Edge>> adj (n + m + 2);
	
	auto add_edge = [&](int u, int v){
		adj[u].push_back({v, 1, (int)adj[v].size()});
		adj[v].push_back({u, 0, (int)adj[u].size() - 1});
	};
	
	for(int i = 0 ; i < k ; ++i){
		int a, b;
		cin >> a >> b;
		b += n;
		
		add_edge(a, b);
	}
	
	for(int i = 1 ; i <= n ; ++i){
		add_edge(0, i);
	}
	
	for(int i = 1 ; i <= m ; ++i){
		add_edge(n + i, n + m + 1);
	}
	
	int s = 0;
	int t = n + m + 1;
	int flow = 0;
	
	while(true){
		vector<pair<int,int>> parent (n + m + 2, {-1, -1});
		queue<int> red;
		
		red.push(s);
		parent[s] = {s, -1};
		
		while(!red.empty()){
			int v = red.front();
			red.pop();
			
			if(v == t) break;
			
			for(int i = 0 ; i < (int)adj[v].size() ; ++i){
				auto &edge = adj[v][i];
				
				if(edge.cap > 0 && parent[edge.to].first == -1){
					parent[edge.to] = {v, i};
					red.push(edge.to);
				}
			}
		} 
		
		if(parent[t].first == -1) break;
		
		for(int v = t ; v != s ; v = parent[v].first){
			int u = parent[v].first;
			int idx = parent[v].second;
			int idx_rev = adj[u][idx].rev;
			
			adj[u][idx].cap -= 1;
			adj[v][idx_rev].cap += 1;
		}
		
		flow ++;
	}
	
	cout << flow << "\n";
	
	for(int u = 1; u <= n; ++u){
        for(auto &edge : adj[u]){
            if(edge.to > n && edge.to <= n + m && edge.cap == 0){
                cout << u << ' ' << edge.to - n << "\n";
            }
        }
    }
	
	return 0;
}
