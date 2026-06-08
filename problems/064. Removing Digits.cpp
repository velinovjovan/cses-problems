#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> dp (n + 1, 1e9);
	dp[0] = 0;
	
	for(int i = 1 ; i <= n ; ++i){
		string temp = to_string(i);
		for(char c : temp){
			int digit = c - '0';
			if(digit){
				dp[i] = min(dp[i], dp[i-digit] + 1);
			}
		}
	}
	
	cout << dp[n];
	
	
	return 0;
	
}
