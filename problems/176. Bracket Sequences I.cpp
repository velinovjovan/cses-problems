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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	if(n & 1){
		cout << 0 << "\n";
		return 0;
	}

	n /= 2;
	
	vector<long long> factorials (2 * n + 1);
	factorials[0] = 1;
	factorials[1] = 1;
	
	for(int i = 2 ; i <= 2 * n ; ++i){
		factorials[i] = factorials[i - 1] * i;
		factorials[i] %= mod;
	}
	
	long long gore = factorials[2 * n];
	long long dole = (factorials[n] * factorials[n]) % mod;
	
	long long ans = divide(divide(gore, dole), n + 1);
	
	cout << ans << "\n";
	
	
	return 0;
}
