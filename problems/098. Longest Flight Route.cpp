#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj (n + 1);
	vector<int> ulazni (n + 1, 0);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		ulazni[b]++;
	}
	
	vector<int> start;
	
	for(int i = 0 ; i < n ; ++i){
		if(ulazni[i] == 0){
			start.push_back(i);
		}
	}
	
	vector<int> maxDist (n + 1, numeric_limits<int>::min());
	vector<int> parent (n + 1);
	
	queue<int> red;
	vector<bool> visited (n + 1, false);
	for(int &x : start){
		red.push(x);
		visited[x] = true;
	}
	
	vector<int> topSort (n);
	
	while(!red.empty()){
		auto node = red.front();
		red.pop();

		topSort.push_back(node);
		
		for(auto &x : adj[node]){
			ulazni[x]--;
			
			if(ulazni[x] == 0){
				red.push(x);
				visited[x] = true;
			}
		}
	}
	
	maxDist[1] = 0;
	parent[1] = -1;
	
	for(auto &x : topSort){
		if(maxDist[x] == numeric_limits<int>::min()) continue;
		 
		for(auto &node : adj[x]){
			maxDist[node] = max(maxDist[node], maxDist[x] + 1);
			if(maxDist[node] == maxDist[x] + 1){
				parent[node] = x;
			}
		}	
	}
	
	if(maxDist[n] == numeric_limits<int>::min()){
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}
	
	cout << maxDist[n] + 1 << "\n";
	
	vector<int> ans;
	ans.reserve(maxDist[n] + 1);
	
	while(n != -1){
		ans.push_back(n);
		n = parent[n];
	}
	
	reverse(ans.begin(), ans.end());
	
	for(int &x : ans){
		cout << x << ' ';
	}
	
	return 0;
}
