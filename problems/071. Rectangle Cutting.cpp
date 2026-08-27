#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, numeric_limits<int>::max()));
    
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            
            for (int v = 1; v < i; ++v) {
                dp[i][j] = min(dp[i][j], dp[v][j] + dp[i - v][j] + 1);
            }
            
            for (int h = 1; h < j; ++h) {
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1);
            }
        }
    }
    
    cout << dp[a][b] << "\n";
    
    return 0;
}
