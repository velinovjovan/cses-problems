#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	const int MOD = 1e9 + 7;
	
	int n, x;
	cin >> n >> x;
	
	vector<int> coins(n);
	
	for(int i = 0 ; i < n ; ++i) cin >> coins[i];
	
	vector<int> dp(x + 1, 0);
	dp[0] = 1;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = coins[i] ; j <= x ; ++j){
			dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
		}
	}
	
	cout << dp[x];
	
	return 0;
}
