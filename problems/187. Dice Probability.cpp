#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= 6 * (i - 1); ++s) {
            if (dp[i - 1][s] == 0) continue;
            for (int k = 1; k <= 6; ++k) {
                dp[i][s + k] += dp[i - 1][s] / 6.0;
            }
        }
    }

    double total_probability = 0.0;
    for (int s = a; s <= b; ++s) {
        total_probability += dp[n][s];
    }

    cout << fixed << setprecision(6) << total_probability << "\n";

    return 0;
}
