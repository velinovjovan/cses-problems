#include<bits/stdc++.h>

using namespace std;

long long max_time = 1e18;
vector<long long> k;
int n, t;

long long check(long long time){
	long long res = 0;
	
	for(int i = 0 ; i < n ; ++i){
		res += time / k[i];
		if(res >= t) return res; 
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> t;
	k.resize(n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> k[i];
	}	
	
	long long i = 1;
	long long j = max_time;
	long long ans = max_time;
	
	while(i <= j){
		long long middle = i + (j - i) / 2;
		long long res = check(middle);
		
		if(res >= t){
			ans = middle;
			j = middle - 1;
		}
		else{
			i = middle + 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
