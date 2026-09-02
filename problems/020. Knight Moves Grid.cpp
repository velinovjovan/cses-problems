#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> grid (n, vector<int> (n, numeric_limits<int>::max()));
	grid[0][0] = 0;
	
	queue<pair<int,int>> red;
	red.push({0, 0});
	
	vector<pair<int,int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, -1}, {2, 1}, {1, -2}, {1, 2}}; 
	
	while(!red.empty()){
		int row, col;
		tie(row, col) = red.front();
		red.pop();
		
		for(auto &x : directions){
			int i, j;
			tie(i, j) = x;
			
			if(row + i < 0 || row + i >= n || col + j < 0 || col + j >= n) continue;
			
			if(grid[row + i][col + j] > grid[row][col] + 1){
				grid[row + i][col + j] = grid[row][col] + 1;
				red.push({row + i, col + j});
			}
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cout << grid[i][j] << ' ';
		}
		
		cout << '\n';
	}
	
	
	return 0;
}
