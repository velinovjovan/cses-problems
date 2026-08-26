#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	const long long INF = numeric_limits<long long>::max();
	
	vector<vector<long long>> distances (n + 1, vector<long long> (n + 1, INF));
	
	for(int i = 1 ; i <= n ; ++i){
		distances[i][i] = 0;
	}
	
	for(int i = 0 ; i < m ; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		
		distances[a][b] = min(distances[a][b], (long long)c);
		distances[b][a] = min(distances[b][a], (long long)c);
	}
	
	for(int k = 1 ; k <= n ; ++k){
		for(int i = 1 ; i <= n ; ++i){
			if(distances[i][k] == INF){
				continue;
			}
			
			for(int j = 1 ; j <= n ; ++j){
				if(distances[k][j] == INF){
					continue;
				}
				
				distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
			}
		}
	}
	
	while(q--){
		int a, b;
		cin >> a >> b;
		
		if(distances[a][b] == INF){
			cout << -1 << "\n";
		}
		else{
			cout << distances[a][b] << "\n";
		}
	}
	
	return 0;
}
