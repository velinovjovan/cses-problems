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
	
	long long ans = 0;
	long long curr = 0;
	
	for(int i = 0 ; i < k ; ++i){
		curr = curr ^ val[i];
	}
	
	for(int i = k ; i < n ; ++i){
		ans = ans ^ curr;
		
		curr = curr ^ val[i - k];
		curr = curr ^ val[i];
	}
	
	ans = ans ^ curr;
	
	cout << ans << "\n";
	
	
	return 0;
}
