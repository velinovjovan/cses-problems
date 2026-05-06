#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	long long total = 0, ans = INT_MAX;
	
	cin >> n;
	long long arr[n];
	
	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
		total += arr[i];
	}
	
	for(int i = 0; i < 1<<n; ++i) 
	{
		long long s = 0;
		
		for(long long j = 0 ; j < n ; ++j){
			if(i & (1 << j)) s += arr[j];
		}
		
		long long curr = abs((total-s)-s);
		ans = min(ans, curr);
	}
	
	cout << ans;
	
	
	return 0;
	
}
