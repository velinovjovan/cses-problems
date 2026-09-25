#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
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
    
    string s;
    cin >> s;

    if(n & 1){
        cout << 0 << "\n";
        return 0;
    }
    
    int b = 0;
    for(char c : s){
        if(c == '(') b++;
        else b--;
        
        if(b < 0){
            cout << 0 << "\n";
            return 0;
        }
    }
    
    int m = n - s.length();
    
    if(m < b || ((m - b) & 1)){
        cout << 0 << "\n";
        return 0;
    }
    
    int x = (m - b) / 2;
    
    vector<long long> factorials(n + 1);
    factorials[0] = 1;
    factorials[1] = 1;
    
    for(int i = 2 ; i <= n ; ++i){
    	factorials[i] = factorials[i - 1] * i;
    	factorials[i] %= mod;
	}
    
    long long gore = factorials[m];
    long long dole = (factorials[x] * factorials[m - x]) % mod;
    
    long long total = divide(gore, dole);
    
    long long invalid = 0;
    if (x > 0) {
        gore = factorials[m];
        dole = (factorials[x - 1] * factorials[m - x + 1]) % mod;
        invalid = divide(gore, dole);
    }
    
    cout << (total - invalid + mod) % mod << "\n";
    
    return 0;
}
