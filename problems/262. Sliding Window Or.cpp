#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	
	vector<long long> val (n);
	val[0] = x;
	
	for(int i = 1 ; i < n ; ++i){
		val[i] = (a * val[i - 1] + b) % c;
	}
	
	vector<long long> pref (n);
	vector<long long> suff (n);
	
	for(int i = 0 ; i < n ; ++i){
		if(i % k == 0){
			pref[i] = val[i];
		}
		else{
			pref[i] = val[i] | pref[i - 1];
		}
	}
	
	for(int i = n - 1 ; i >= 0 ; --i){
		if((i + 1) % k == 0 || i == n - 1){
			suff[i] = val[i];
		}
		else{
			suff[i] = val[i] | suff[i + 1];
		}
	}
	
	long long ans = 0;
	
	for(int i = k - 1 ; i < n ; ++i){
		if((i + 1) % k == 0){
			ans = ans ^ pref[i];
		}
		else{
			ans = ans ^ (suff[i - k + 1] | pref[i]);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
