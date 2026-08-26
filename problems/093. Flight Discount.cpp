#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int,int>>> adj (n + 1);
	vector<vector<pair<int,int>>> rev (n + 1);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({b, c});
		rev[b].push_back({a, c});
	}
	
	const long long INF = numeric_limits<long long>::max();
	
	vector<long long> distance (n + 1, INF);	
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> red;
	distance[n] = 0;
	red.push({0, n});
	
	while(!red.empty()){
		auto node = red.top();
		red.pop();
		
		if(node.first != distance[node.second]){
			continue;
		}
		
		for(auto &x : rev[node.second]){
			if(distance[x.first] > distance[node.second] + x.second){
				distance[x.first] = distance[node.second] + x.second;
				red.push({distance[x.first], x.first});
			}
		}
	}
	
	vector<long long> distanceOne (n + 1, INF);
	distanceOne[1] = 0;
	red.push({0, 1});
	
	while(!red.empty()){
		auto node = red.top();
		red.pop();
		
		if(node.first != distanceOne[node.second]){
			continue;
		}
		
		for(auto &x : adj[node.second]){
			if(distanceOne[x.first] > distanceOne[node.second] + x.second){
				distanceOne[x.first] = distanceOne[node.second] + x.second;
				red.push({distanceOne[x.first], x.first});
			}
		}
	}
	
	long long ans = INF;
	
	for(int i = 1 ; i <= n ; ++i){
		if(distanceOne[i] == INF){
			continue;
		}
		
		for(auto &x : adj[i]){
			if(distance[x.first] == INF){
				continue;
			}
			
			ans = min(ans, distanceOne[i] + x.second / 2 + distance[x.first]);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
