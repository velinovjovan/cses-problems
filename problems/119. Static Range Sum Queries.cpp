#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	vector<long long> dp (n + 1);
	dp[0] = 0;
	dp[1] = a[0];
	for(int i = 1 ; i < n + 1 ; ++i){
		dp[i] = dp[i - 1] + a[i - 1];
	}
	
	while(q--){
		int a, b;
		cin >> a >> b;
		
		cout << dp[b] - dp[a - 1] << "\n";
	}
	
	
	return 0;
}
