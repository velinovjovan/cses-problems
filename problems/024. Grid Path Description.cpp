#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const vector<pair<int,int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
const string moves = "UDRL";
long long answer;
bool visited[N][N];
string input;

const vector<pair<int,int>> eight_dirs = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

bool isInside(int row, int col) {
	return 0 <= min(row, col) && max(row, col) < N;
}
bool isEmpty(int row, int col) {
	return isInside(row, col) && !visited[row][col];
}

void dfs(int row, int col, int i) {
	if (row >= 1 && col >= 1 && isEmpty(row-1, col) && isEmpty(row, col-1) && !isEmpty(row-1, col-1)) {
		return;
	}
	if (row >= 1 && col <= N - 2 && isEmpty(row-1, col) && isEmpty(row, col+1) && !isEmpty(row-1, col+1)) {
		return;
	}
	if (row <= N-2 && col >= 1 && isEmpty(row+1, col) && isEmpty(row, col-1) && !isEmpty(row+1, col-1)) {
		return;
	}
	if (row <= N-2 && col <= N - 2 && isEmpty(row+1, col) && isEmpty(row, col+1) && !isEmpty(row+1, col+1)) {
		return;
	}
	
	if (isEmpty(row-1, col) && isEmpty(row+1, col) && !isEmpty(row,col-1) && !isEmpty(row,col+1)) {
		return;
	}
	if (!isEmpty(row-1, col) && !isEmpty(row+1, col) && isEmpty(row,col-1) && isEmpty(row,col+1)) {
		return;
	}
	
	if (row == N - 1 && col == 0) {
		if (i == N * N - 1) {
			answer++;
		}
		return;
	}
	for (int j = 0; j < 4; j++) {
		if (input[i] != '?' && input[i] != moves[j]) {
			continue;
		}
		const pair<int,int>& dir = dirs[j];
		int r2 = row + dir.first;
		int c2 = col + dir.second;
		if (isInside(r2, c2) && !visited[r2][c2]) {
			visited[r2][c2] = true;
			dfs(r2, c2, i+1);
			visited[r2][c2] = false;
		}
	}
}

int main() {
	cin >> input;
	visited[0][0] = true;
	dfs(0, 0, 0);
	
	cout << answer << "\n";
	
	return 0;
}
