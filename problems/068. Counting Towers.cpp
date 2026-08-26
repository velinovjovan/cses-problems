#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

vector<vector<long long>> dp (1e6 + 1, vector<long long> (2));

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		dp[1][0] = 1;
		dp[1][1] = 1;
		
		for(int i = 2 ; i <= n ; ++i){
			dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1]) % mod;
			dp[i][1] = (4LL * dp[i - 1][1] + dp[i - 1][0]) % mod;
		}
		
		cout << (dp[n][0] + dp[n][1]) % mod << '\n';
	}
	
	return 0;
}
