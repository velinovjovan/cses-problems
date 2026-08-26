#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

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
	
	vector<long long> totalDist (n + 1, 0);
	
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
	
	totalDist[1] = 1;
	
	for(auto &x : topSort){
		for(auto &node : adj[x]){
			totalDist[node] += totalDist[x];
			totalDist[node] %= mod;
		}	
	}
	
	cout << totalDist[n]<< "\n";

	return 0;
}
