#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
	long long ans = 1;
	a %= mod;
	
	while(b){
		if(b & 1){
			ans = (ans * a)  % mod;
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
	
	int n;
	cin >> n;
	
	vector<long long> factorials (n + 1);
	factorials[0] = 1;
	factorials[1] = 1;
	
	for(int i = 2 ; i <= n ; ++i){
		factorials[i] = factorials[i - 1] * i;
		factorials[i] %= mod;
	}
	
	long long ans = factorials[n];
	
	for(int i = 1 ; i <= n ; ++i){
		long long gore = factorials[n];
		long long dole = (factorials[i] * factorials[n - i]) % mod;
		
		long long ways = divide(gore, dole);
		long long term = (ways * factorials[n - i]) % mod;
		
		if (i % 2 != 0) ans = (ans - term + mod) % mod;
		else ans = (ans + term) % mod;
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
