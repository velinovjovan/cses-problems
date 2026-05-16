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
	
	sort(a.begin(), a.end());
	
	long long median =  a[n/2];
	long long ans = 0;
	
	for(int i = 0 ; i < n ; ++i){
		ans+= abs(median - a[i]);
	}
	
	cout << ans;
	
	
	return 0;
	
}
