#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> grid (n, vector<char> (m));
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> grid[i][j];
		}
	}
	
	vector<char> chars = {'A', 'B', 'C', 'D'};
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			
			for(auto &c : chars){
				if(i > 0 && grid[i - 1][j] == c){
					continue;
				}
				
				if(j > 0 && grid[i][j - 1] == c){
					continue;
				}
				
				if(grid[i][j] == c){
					continue;
				}
				
				grid[i][j] = c;
				break;
			}
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cout << grid[i][j];
		}
		
		cout << '\n';
	}
	
	return 0;
}
