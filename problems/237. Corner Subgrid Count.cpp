#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("popcnt,avx2")

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<bitset<3000>> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	long long ans = 0;
	for(int i = 0 ; i < n - 1 ; ++i){
		for(int j = i + 1 ; j < n ; ++j){
			long long count = (long long)(a[i] & a[j]).count();
			
			if(count > 1){
				ans += (count * (count - 1)) / 2;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
