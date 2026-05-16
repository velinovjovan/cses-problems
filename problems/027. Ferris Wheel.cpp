#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	long long x;
	cin >> n >> x;
	
	vector<long long> a (n);
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int i = 0;
	int j = n-1;
	int ans = 0;
	
	while(i <= j){
		
		if(a[i] + a[j] <= x){
			ans++;
			++i;
			--j;
		}
		else{
			ans++;
			--j;
		}
	}
	
	cout << ans;
	
	
	return 0;
	
}
