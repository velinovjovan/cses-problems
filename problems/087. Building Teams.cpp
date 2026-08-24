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
	vector<int> color (n + 1, 0);
	
	queue<int> red;
	red.push(1);
	visited[1] = true;
	color[1] = 1;
	
	bool flag = false;
	while(!red.empty() && !flag){
		int idx = red.front();
		red.pop();
		
		for(auto &x : adj[idx]){
			if(color[idx] == color[x]){
				flag = true;
				break;
			}
			
			if(!visited[x]){
				red.push(x);
				visited[x] = true;
				if(color[idx] == 1) color[x] = 2;
				else color[x] = 1;
			}
		}
	}
	
	if(flag){
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}
	
	for(int i = 2 ; i <= n ; ++i){
		if(!visited[i]){
			queue<int> red;
			red.push(i);
			visited[i] = true;
			color[i] = 1;
			bool flag = false;
			
			while(!red.empty() && !flag){
				int idx = red.front();
				red.pop();
				
				for(auto &x : adj[idx]){
					if(color[idx] == color[x]){
						flag = true;
						break;
					}
					
					if(!visited[x]){
						red.push(x);
						visited[x] = true;
						if(color[idx] == 1) color[x] = 2;
						else color[x] = 1;
					}
				}
			}
			
			if(flag){
				cout << "IMPOSSIBLE" << "\n";
				return 0;
			}
		}
	}
	
	
	for(int i = 1 ; i <= n ; ++i){
		cout << color[i] << " ";
	}
	
	
	return 0;
}
