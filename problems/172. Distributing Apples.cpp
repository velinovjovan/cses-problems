#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
	long long ans = 1;
	a %= mod;
	
	while(b){
		if(b & 1){
			ans = (ans * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	
	return ans;
}

long long divide(long long a, long long b){
	return (a * power(b, mod - 2)) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b;
	cin >> a >> b;
	
	int n = b + a - 1;
	int k = a - 1;
	
	long long gore = 1;
	
	for(int i = 2 ; i <= n ; ++i){
		gore *= i;
		gore %= mod;		
	}
	
	long long dole1 = 1;
	long long dole2 = 1;
	
	for(int i = 2 ; i <= k ; ++i){
		dole1 *= i;
		dole1 %= mod;
	}
	
	for(int i = 2 ; i <= n - k ; ++i){
		dole2 *= i;
		dole2 %= mod;
	}
	
	long long dole = (dole1 * dole2) % mod;
	
	cout << divide(gore, dole) << "\n";
	
	
	return 0;
}
