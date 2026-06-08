#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> dp (n + 1, 0);
	
	dp[0] = 1;
	
	for(int i = 1 ; i <= n ; ++i) 
	{
		for(int j = 1 ; j <= 6 ; ++j) 
		{
			if(i - j < 0) break;
			
			dp[i] += dp[i-j];
			dp[i] %= 1000000007;
		}
	}
	
	
	cout << dp[n];
	
	
	return 0;
	
}

