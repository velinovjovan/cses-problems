#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long mod_exp = 2 * (1e9 + 6); 

long long power(long long a, long long b){
	long long ans = 1;
	a %= mod;
	
	while(b){
		if(b & 1){
			ans *= a;
			ans %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
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
	
	vector<pair<long long, long long>> factors (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> factors[i].first >> factors[i].second;
	}
	
	long long numfact = 1;
	long long numfact_exp = 1; 
	
	for(auto &factor : factors){
		numfact *= (factor.second + 1);
        numfact %= mod;
        
        numfact_exp *= (factor.second + 1);
        numfact_exp %= mod_exp; 
	}
	
	long long sumfact = 1;
	
	for(auto &factor : factors){
        long long numerator = (power(factor.first, factor.second + 1) - 1 + mod) % mod;
		sumfact *= divide(numerator, factor.first - 1);
		sumfact %= mod; 
	}
	
	long long prodfact = 1;
    
    for(auto &factor : factors){
        long long total_k = (factor.second * numfact_exp) % mod_exp;
        long long final_k = total_k / 2;
        
        prodfact *= power(factor.first, final_k);
        prodfact %= mod;
    }
	
	cout << numfact << ' ' << sumfact << ' ' << prodfact << "\n";

	return 0;
}
