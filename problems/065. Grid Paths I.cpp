#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int MOD = 1e9 + 7;

	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n, 0));

	for(int i = 0 ; i < n ; ++i){
		string temp;
		cin >> temp;
		
		for(int j = 0 ; j < n ; ++j){
			if(temp[j] == '*') matrix[i][j] = -1;
		}
	}

	if(matrix[0][0] == -1){
		cout << 0;
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = 1;

	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(matrix[i][j] == -1) continue;
			if(i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if(j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[n - 1][n - 1];


	return 0;

}
