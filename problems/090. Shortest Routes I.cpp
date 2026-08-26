#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int,int>>> adj (n + 1);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({b, c});
	}
	
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> red;	
	vector<long long> distances (n + 1, numeric_limits<long long>::max());
	
	distances[1] = 0;
	red.push({0, 1});
	
	while(!red.empty()){
		auto node = red.top();
		red.pop();
		
		if(node.first != distances[node.second]){
			continue;
		}
		
		for(auto &x : adj[node.second]){
			if(distances[x.first] > distances[node.second] + x.second){
				distances[x.first] = distances[node.second] + x.second;
				red.push({distances[x.first], x.first});
			}
		}
	}
	
	for(int i = 1 ; i <= n ; ++i){
		cout << distances[i] << " ";
	}
	
	return 0;
}
