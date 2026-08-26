#include<bits/stdc++.h>
 
using namespace std;
 
const long long mod = 1e9 + 7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	vector<vector<long long>> dp (n, vector<long long> (m + 1, 0));
	
	for(int j = 1 ; j <= m ; ++j){
		if(a[0] == 0 || a[0] == j){
			dp[0][j] = 1;
		}
	}
	
	for(int i = 1 ; i < n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(a[i] != 0 && a[i] != j){
				continue;
			}
			
			dp[i][j] = dp[i - 1][j];
			
			if(j > 1){
				dp[i][j] += dp[i - 1][j - 1];
			}
			
			if(j < m){
				dp[i][j] += dp[i - 1][j + 1];
			}
			
			dp[i][j] %= mod;
		}
	}
	
	long long ans = 0;
	
	for(int j = 1 ; j <= m ; ++j){
		ans += dp[n - 1][j];
		ans %= mod;
	}
	
	cout << ans;
	
	return 0;
}
