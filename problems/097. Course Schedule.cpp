#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n + 1);
	vector<int> ulazni(n + 1, 0);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		ulazni[b]++;
	}
	
	queue<int> red;
	
	for(int i = 1 ; i <= n ; ++i){
		if(ulazni[i] == 0){
			red.push(i);
		}
	}
	
	vector<int> ans;
	ans.reserve(n);
	
	while(!red.empty()){
		auto node = red.front();
		red.pop();
		
		ans.push_back(node);
		
		for(auto &x : adj[node]){
			ulazni[x]--; 
			
			if(ulazni[x] == 0){
				red.push(x);
			}
		}
	}

	if(ans.size() != n){
		cout << "IMPOSSIBLE\n";
	}
	else{
		for(auto &x : ans){
			cout << x << ' ';
		}
	}
	
	return 0;
}
