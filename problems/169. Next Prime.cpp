#include<bits/stdc++.h>

using namespace std;

long long power(long long a, long long b, long long mod){
	long long res = 1;
	a %= mod;
	
	while(b){
		if(b & 1){
			res = (long long)((__int128_t)res * a % mod);
		}
		b >>= 1;
		a = (long long)((__int128_t)a * a % mod);
	}
	
	return res;
}

bool miillerTest(long long d, long long n, long long a){
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1){
        return true;
    }

    while (d != n - 1){
        x = (long long)((__int128_t)x * x % n);
        d *= 2;

        if (x == 1)      return false;
        if (x == n - 1)  return true;
    }

    return false;
}

bool isPrime(long long n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false; 

    long long d = n - 1;
    while (d % 2 == 0){
    	d /= 2;
	}

    vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    for (long long a : bases) {
        if (n <= a) break;
        if (!miillerTest(d, n, a)){
            return false;
        }
    }

    return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		
		while(true){
			++n;
			if(isPrime(n)) break;
		}
		
		cout << n << "\n";
	}
	
	return 0;
}
