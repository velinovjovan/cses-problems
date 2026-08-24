#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj (100005);
int parent[100005];
bool visited[100005];

int start, finish;

bool dfs(int node){
	visited[node] = true;
	
	for(auto &x : adj[node]){
		if(parent[node] == x){
			continue;
		}
		
		if(visited[x]){
			start = x;
			finish = node;
			return true;
		}
		
		parent[x] = node;
		
		if(dfs(x)){
			return true;
		}
	}
	
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			if(dfs(i)){
				vector<int> res;
				
				int temp = finish;
				res.push_back(temp);
				
				while(temp != start){
					temp = parent[temp];
					res.push_back(temp);
				}
				
				res.push_back(finish);
				
				cout << res.size() << "\n";
				
				for(auto &x : res){
					cout << x << " ";
				}
				
				cout << "\n";
				return 0;
			}
		}
	}
	
	cout << "IMPOSSIBLE\n";
	
	return 0;
}
