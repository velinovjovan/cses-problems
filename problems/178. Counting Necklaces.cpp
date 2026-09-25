#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
	long long res = 1;
	a %= mod;
	
	while(b){
		if(b & 1){
			res = (res * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}

long long divide(long long a, long long b){
	return (a * power(b, mod - 2)) % mod;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	long long ans = 0;
	
	for(int i = 0 ; i < n ; ++i){
		ans += power(m, gcd(i, n));
		ans %= mod;
	}
	
	ans = divide(ans, n);
	
	cout << ans << "\n";
	
	
	return 0;
}
