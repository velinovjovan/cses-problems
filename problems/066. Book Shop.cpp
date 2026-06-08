#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> pr(n);
    vector<int> pg(n);

    for (int i = 0 ; i < n ; ++i) cin >> pr[i];
    for (int i = 0 ; i < n ; ++i) cin >> pg[i];
    
    vector<int> dp(x + 1, 0);

    for (int i = 0 ; i < n ; ++i) {
        for (int j = x ; j >= pr[i] ; --j) {
            dp[j] = max(dp[j], dp[j - pr[i]] + pg[i]);
        }
    }
    
    cout << dp[x];


    return 0;

}

