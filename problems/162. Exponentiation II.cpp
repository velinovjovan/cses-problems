#include <iostream>

using namespace std;

long long exp(long long a, long long b, long long mod){
    long long res = 1;
    a %= mod;
    
    while (b > 0){
        if (b & 1){
            res = (res * a) % mod;
        }
        
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const long long MOD = 1e9 + 7;

    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        long long exponent = exp(b, c, MOD - 1);
        long long ans = exp(a, exponent, MOD);

        cout << ans << "\n";
    }

    return 0;
}
