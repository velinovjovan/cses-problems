#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> coins (n);
	
	long long x = 0;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> coins[i];
		x += coins[i];
	}
	
	vector<int> dp (x + 1);
	dp[0] = 1;
	
	for(auto &coin : coins){
		for(int i = x ; i >= 0 ; --i){
			if(i - coin >= 0 && dp[i - coin]){
				dp[i] = 1;	
			}
		}
	}
	
	
	vector<int> ans;
	for(int i = 1 ; i <= x ; ++i){
		if(dp[i]){
			ans.push_back(i);
		}
	}
	
	cout << ans.size() << '\n';
	
	for(auto &val : ans){
		cout << val << ' ';
	}
	
	return 0;
}
