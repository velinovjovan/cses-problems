#include<bits/stdc++.h>

using namespace std;

vector<string> board(8);
bool col_occupied[8];
bool diag1_occupied[15];
bool diag2_occupied[15];

int ans = 0;

void solve(int row) {
    if (row == 8) {
        ans++;
        return;
    }

    for (int col = 0 ; col < 8 ; ++col) {
        if (board[row][col] == '*' || col_occupied[col] || diag1_occupied[row - col + 7] || diag2_occupied[row + col]) continue;

        col_occupied[col] = true;
        diag1_occupied[row - col + 7] = true;
        diag2_occupied[row + col] = true;

        solve(row + 1);
        
        col_occupied[col] = false;
        diag1_occupied[row - col + 7] = false;
        diag2_occupied[row + col] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	for(auto &s : board){
		cin >> s;
	}

    solve(0);

    cout << ans << "\n";

    return 0;
}
