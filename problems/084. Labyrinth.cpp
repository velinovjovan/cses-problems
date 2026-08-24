#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> matrix (n, vector<char> (m));
	pair<int, int> start;
	pair<int, int> end;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> matrix[i][j];
			if(matrix[i][j] == 'A') start = {i, j};
			if(matrix[i][j] == 'B') end = {i, j};
		}
	}
	
	vector<vector<char>> prev (n, vector<char> (m));
	vector<vector<bool>> visited (n, vector<bool> (m));
	
	bool flag = false;
		
	queue<pair<int,int>> red;
	red.push(start);
	visited[start.first][start.second] = true;
	prev[start.first][start.second] = 'E';
		
	while(!red.empty()){
		auto cord = red.front();
		red.pop();
			
		if(matrix[cord.first][cord.second] == 'B'){
			flag = true;
			break;
		}
			
		if(cord.first > 0 && matrix[cord.first - 1][cord.second] != '#' && !visited[cord.first - 1][cord.second]){
			red.push({cord.first - 1, cord.second});
			visited[cord.first - 1][cord.second] = true;
			prev[cord.first - 1][cord.second] = 'U';
		}
								
		if(cord.second > 0 && matrix[cord.first][cord.second - 1] != '#' && !visited[cord.first][cord.second - 1]){
			red.push({cord.first, cord.second - 1});
			visited[cord.first][cord.second - 1] = true;
			prev[cord.first][cord.second - 1] = 'L';
		}
					
		if(cord.first < n - 1 && matrix[cord.first + 1][cord.second] != '#' && !visited[cord.first + 1][cord.second]){
			red.push({cord.first + 1, cord.second});
			visited[cord.first + 1][cord.second] = true;
			prev[cord.first + 1][cord.second] = 'D';
		}
				
		if(cord.second < m - 1 && matrix[cord.first][cord.second + 1] != '#' && !visited[cord.first][cord.second + 1]){
			red.push({cord.first, cord.second + 1});
			visited[cord.first][cord.second + 1] = true;
			prev[cord.first][cord.second + 1] = 'R'; 
		}
	}
	
	if(flag){
		pair<int,int> cord = end;
		
		int count = 0;
		string ans;
		while(matrix[cord.first][cord.second] != 'A'){
			ans.push_back(prev[cord.first][cord.second]);
			count ++;
			
			if(prev[cord.first][cord.second] == 'U'){
				cord.first ++;
			}
			else if(prev[cord.first][cord.second] == 'D'){
				cord.first --;
			}
			else if(prev[cord.first][cord.second] == 'L'){
				cord.second ++;
			}
			else{
				cord.second --;
			}
		}
		
		reverse(ans.begin(), ans.end());
		cout << "YES" << "\n";
		cout << count << "\n";
		cout << ans; 
	}
	else{
		cout << "NO";
	}
	
	
	return 0;
	
}
