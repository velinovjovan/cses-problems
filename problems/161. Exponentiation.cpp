#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long exp(long long a, long long b){
	
	long long res = 1;
	
	while(b){
		if(b & 1){
			res *= a;
			res %= mod;
		}
		
		a *= a;
		a %= mod;
		
		b >>= 1;
	}
	
	
	return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	while(n--){
		int a, b;
		cin >> a >> b;
		
		cout << exp(a, b) << "\n";
	}
	
	
	return 0;
	
}
