#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	const int MOD = 1000000007;

	int n, m;
	cin >> n >> m;

	vector<int> a (n);

	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}

	vector<vector<int>> dp (n, vector<int> (m + 1, 0));

	if(a[0] == 0){
		for(int j = 1 ; j <= m ; ++j){
			dp[0][j] = 1;
		}
	}
	else{
		dp[0][a[0]] = 1;
	}

	for(int i = 1 ; i < n ; ++i){
		if(a[i] == 0){
			for(int j = 1 ; j <= m ; ++j){
				dp[i][j] = dp[i - 1][j];

				if(j > 1){
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= MOD;
				}

				if(j < m){
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= MOD;
				}
			}
		}
		else{
			int j = a[i];

			dp[i][j] = dp[i - 1][j];

			if(j > 1){
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= MOD;
			}

			if(j < m){
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
		}
	}

	long long ans = 0;

	if(a[n - 1] == 0){
		for(int j = 1 ; j <= m ; ++j){
			ans += dp[n - 1][j];
			ans %= MOD;
		}
	}
	else{
		ans = dp[n - 1][a[n - 1]];
	}

	cout << ans;
	

	return 0;

}
