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
    return (a * power(b , mod - 2)) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    long long n2 = n * n;  
    long long ans = 0;
    
    ans = (ans + power(2, n2)) % mod;
    ans = (ans + power(2, (n2 + 1) / 2)) % mod;
    ans = (ans + 2 * power(2, (n2 + 3) / 4)) % mod;
    ans = divide(ans, 4);
    
    cout << ans << "\n";

    return 0;
}
