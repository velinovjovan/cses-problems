#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long n;
	cin >> n;
	
	long ans = n*(n+1)/2;
	long temp;
	for (int i = 0 ; i < n-1 ; ++i){
		cin >> temp;
		ans -= temp;
	}
	
	cout << ans;
	
	
	return 0;
}
