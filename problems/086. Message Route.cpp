#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj (n + 1);
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<bool> visited (n + 1, false);
	vector<int> prev (n + 1);
	
	queue<int> red;
	red.push(1);
	visited[1] = true;
	bool flag = false;
	
	while(!red.empty()){
		int idx = red.front();
		red.pop();
		
		if(idx == n){
			flag = true;
			break;
		}
		
		for(auto &x : adj[idx]){
			if(!visited[x]){
				red.push(x);
				visited[x] = true;
				prev[x] = idx;
			}
		}
	}
	
	if(flag){
		stack<int> ans;
		int temp = n;
		
		while(temp != 1){
			ans.push(prev[temp]);
			temp = prev[temp];
		}
		
		cout << ans.size() + 1 << "\n";
		while(!ans.empty()){
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << n;
	}
	else{
		cout << "IMPOSSIBLE" << "\n";
	}
	
	return 0;
}
