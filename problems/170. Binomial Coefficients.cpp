#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maks = 1e6 + 10;

long long fact(long long a){
	long long ans = 1;
	
	for(int i = 2 ; i <= a ; ++i){
		ans *= i;
		ans %= mod;
	}
	
	return ans;
}

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
	
	int n;
	cin >> n;
	
	vector<long long> factorials(maks + 1);
	factorials[0] = 1;
	factorials[1] = 1;
	
	for(int i = 2 ; i <= maks ; ++i){
		factorials[i] = factorials[i - 1] * i;
		factorials[i] %= mod;
	}
	
	
	while(n--){
		long long n, k;
		cin >> n >> k;
		
		long long gore = factorials[n];
		long long dole = (factorials[k] * factorials[n - k]) % mod;
		
		cout << divide(gore, dole) << "\n";
	}
	
	
	return 0;
}
