#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<long long> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	vector<long long> dp (n);
	dp[0] = a[0];
	long long maks = a[0];
	
	for(int i = 1 ; i < n ; ++i){
		dp[i] = max(dp[i-1] + a[i], a[i]);
		maks = max(maks, dp[i]);
	}
	
	cout << maks;
	
	
	return 0;
	
}
