#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> matrix (n, vector<int> (m, 0));
	
	char c;
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> c;
			if(c == '.') matrix[i][j]++;
		}
	}
	
	int ans = 0;
	vector<vector<bool>> visited (n, vector<bool> (m, false));
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(matrix[i][j] && !visited[i][j]){
				queue<pair<int,int>> red;
				red.push({i,j});
				visited[i][j] = true;
				
				while(!red.empty()){
					pair<int,int> cord = red.front();
					red.pop();
					
					if(cord.first > 0 && matrix[cord.first - 1][cord.second] && !visited[cord.first - 1][cord.second]){
						red.push({cord.first - 1, cord.second});
						visited[cord.first - 1][cord.second] = true;
					}
					
					if(cord.second > 0 && matrix[cord.first][cord.second - 1] && !visited[cord.first][cord.second - 1]){
						red.push({cord.first, cord.second - 1});
						visited[cord.first][cord.second - 1] = true;
					}
					
					if(cord.first < n - 1 && matrix[cord.first + 1][cord.second] && !visited[cord.first + 1][cord.second]){
						red.push({cord.first + 1, cord.second});
						visited[cord.first + 1][cord.second] = true;
					}
					
					if(cord.second < m - 1 && matrix[cord.first][cord.second + 1] && !visited[cord.first][cord.second + 1]){
						red.push({cord.first, cord.second + 1});
						visited[cord.first][cord.second + 1] = true;
					}
				}
				
				ans ++;
			}
		}
	}
	
	cout << ans;
	
	
	return 0;
}
