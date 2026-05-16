#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<pair<long long, long long>> a (n);
	
	long long temp;
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i].second >> a[i].first;
	}
	
	sort(a.begin(), a.end());
	
	long long currEnd = 0;
	int ans = 0;
	
	for(int i = 0 ; i < n ; ++i){
		if(currEnd <= a[i].second){
			currEnd = a[i].first;
			ans++;
		}
	}
	
	cout << ans;
	
	
	return 0;
	
}
