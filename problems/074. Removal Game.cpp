#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));


    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (len == 1) {
                dp[i][j] = x[i];
            } 
			else if (len == 2) {
                dp[i][j] = max(x[i], x[j]);
            } 
			else{
                long long left = x[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                long long right = x[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(left, right);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
    
    return 0;
}
