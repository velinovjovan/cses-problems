#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<tuple<int,int,int>> edges;
	vector<vector<int>> adj (n + 1);
	vector<vector<int>> rev (n + 1);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		
		edges.push_back({a, b, -c});
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	
	vector<bool> fromStart (n + 1, false);
	vector<bool> canReach (n + 1, false);
	
	queue<int> red;
	
	red.push(1);
	fromStart[1] = true;
	
	while(!red.empty()){
		int node = red.front();
		red.pop();
		
		for(auto &x : adj[node]){
			if(!fromStart[x]){
				fromStart[x] = true;
				red.push(x);
			}
		}
	}
	
	red.push(n);
	canReach[n] = true;
	
	while(!red.empty()){
		int node = red.front();
		red.pop();
		
		for(auto &x : rev[node]){
			if(!canReach[x]){
				canReach[x] = true;
				red.push(x);
			}
		}
	}
	
	const long long INF = numeric_limits<long long>::max();
	
	vector<long long> distance (n + 1, INF);
	distance[1] = 0;
	
	for(int i = 0 ; i < n - 1 ; ++i){
		bool changed = false;
		
		for(auto &x : edges){
			int a, b, c;
			tie(a, b, c) = x;
			
			if(distance[a] != INF && distance[b] > distance[a] + c){
				distance[b] = distance[a] + c;
				changed = true;
			}
		}
		
		if(!changed){
			break;
		}
	}
	
	for(auto &x : edges){
		int a, b, c;
		tie(a, b, c) = x;
		
		if(fromStart[a] && canReach[b] && distance[a] != INF && distance[b] > distance[a] + c){
			cout << -1 << "\n";
			return 0;
		}
	}
	
	cout << -distance[n] << "\n";
	
	return 0;
}
