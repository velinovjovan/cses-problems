#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> matrix (n, vector<char> (m));
	pair<int, int> start;
	vector<pair<int,int>> monsters;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> matrix[i][j];
			
			if(matrix[i][j] == 'A'){
				start = {i, j};
			}
			
			if(matrix[i][j] == 'M'){
				monsters.push_back({i, j});
			}
		}
	}
	
	vector<vector<int>> monstDist (n, vector<int> (m, numeric_limits<int>::max()));
	
	queue<pair<int, int>> red;
	
	for(auto &x : monsters){
		red.push(x);
		monstDist[x.first][x.second] = 0;
	}
	
	while(!red.empty()){
		auto cord = red.front();
		red.pop();
		
		if(cord.first > 0 && matrix[cord.first - 1][cord.second] != '#' && 
			monstDist[cord.first - 1][cord.second] > monstDist[cord.first][cord.second] + 1){
			
			red.push({cord.first - 1, cord.second});
			monstDist[cord.first - 1][cord.second] = monstDist[cord.first][cord.second] + 1;
		}
		
		if(cord.second > 0 && matrix[cord.first][cord.second - 1] != '#' && 
			monstDist[cord.first][cord.second - 1] > monstDist[cord.first][cord.second] + 1){
			
			red.push({cord.first, cord.second - 1});
			monstDist[cord.first][cord.second - 1] = monstDist[cord.first][cord.second] + 1;
		}
		
		if(cord.first < n - 1 && matrix[cord.first + 1][cord.second] != '#' && 
			monstDist[cord.first + 1][cord.second] > monstDist[cord.first][cord.second] + 1){
			
			red.push({cord.first + 1, cord.second});
			monstDist[cord.first + 1][cord.second] = monstDist[cord.first][cord.second] + 1;
		}
		
		if(cord.second < m - 1 && matrix[cord.first][cord.second + 1] != '#' && 
			monstDist[cord.first][cord.second + 1] > monstDist[cord.first][cord.second] + 1){
			
			red.push({cord.first, cord.second + 1});
			monstDist[cord.first][cord.second + 1] = monstDist[cord.first][cord.second] + 1;
		}
	}
	
	vector<vector<int>> playerDist (n, vector<int> (m, numeric_limits<int>::max()));
	vector<vector<bool>> visited (n, vector<bool> (m, false));
	vector<vector<pair<int,int>>> prev (n, vector<pair<int,int>> (m));
	
	red.push(start);
	visited[start.first][start.second] = true;
	playerDist[start.first][start.second] = 0;
	
	while(!red.empty()){
		auto cord = red.front();
		red.pop();
		
		if(cord.first > 0 && matrix[cord.first - 1][cord.second] != '#' && !visited[cord.first - 1][cord.second]){
			red.push({cord.first - 1, cord.second});
			visited[cord.first - 1][cord.second] = true;
			playerDist[cord.first - 1][cord.second] = playerDist[cord.first][cord.second] + 1;
			prev[cord.first - 1][cord.second] = cord;
		}
		
		if(cord.second > 0 && matrix[cord.first][cord.second - 1] != '#' && !visited[cord.first][cord.second - 1]){
			red.push({cord.first, cord.second - 1});
			visited[cord.first][cord.second - 1] = true;
			playerDist[cord.first][cord.second - 1] = playerDist[cord.first][cord.second] + 1;
			prev[cord.first][cord.second - 1] = cord;
		}
		
		if(cord.first < n - 1 && matrix[cord.first + 1][cord.second] != '#' && !visited[cord.first + 1][cord.second]){
			red.push({cord.first + 1, cord.second});
			visited[cord.first + 1][cord.second] = true;
			playerDist[cord.first + 1][cord.second] = playerDist[cord.first][cord.second] + 1;
			prev[cord.first + 1][cord.second] = cord;
		}
		
		if(cord.second < m - 1 && matrix[cord.first][cord.second + 1] != '#' && !visited[cord.first][cord.second + 1]){
			red.push({cord.first, cord.second + 1});
			visited[cord.first][cord.second + 1] = true;
			playerDist[cord.first][cord.second + 1] = playerDist[cord.first][cord.second] + 1;
			prev[cord.first][cord.second + 1] = cord;
		}
	}
	
	pair<int,int> ans = {-1,-1};
	
	for(int i = 0 ; i < n ; ++i){
		
		if(matrix[i][0] != '#' && playerDist[i][0] < monstDist[i][0]){
			ans = {i, 0};
			break;
		}
		
		if(matrix[i][m - 1] != '#' && playerDist[i][m - 1] < monstDist[i][m - 1]){
			ans = {i, m - 1};
			break;
		}
	}
	
	if(ans.first == -1){
		for(int i = 0 ; i < m ; ++i){
			
			if(matrix[0][i] != '#' && playerDist[0][i] < monstDist[0][i]){
				ans = {0, i};
				break;
			}
			
			if(matrix[n - 1][i] != '#' && playerDist[n - 1][i] < monstDist[n - 1][i]){
				ans = {n - 1, i};
				break;
			}
		}
	}
	
	if(ans.first == -1){
		cout << "NO\n";
		return 0;
	}
	
	string res;
	
	cout << "YES\n";
	cout << playerDist[ans.first][ans.second] << "\n";
	
	while(matrix[ans.first][ans.second] != 'A'){
		pair<int,int> temp = prev[ans.first][ans.second];
		
		if(temp.first < ans.first){
			res.push_back('D');
		}
		
		if(temp.first > ans.first){
			res.push_back('U');
		}
		
		if(temp.second < ans.second){
			res.push_back('R');
		}
		
		if(temp.second > ans.second){
			res.push_back('L');
		}
		
		ans = temp;
	}
	
	reverse(res.begin(), res.end());
	
	cout << res << "\n";
	
	return 0;
}
