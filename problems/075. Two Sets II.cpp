#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    long long sum = (long long)n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    int target = sum / 2;
    
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    

    for (int i = 1 ; i < n ; ++i) {
        for (int j = target ; j >= i ; --j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    
    cout << dp[target] << "\n";
    
    return 0;
}
