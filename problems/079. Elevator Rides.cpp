#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, w;
    cin >> n >> w;
    
    vector<int> weight(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> weight[i];
    }
    
    vector<pair<int, int>> dp(1 << n);
    
    dp[0] = {1, 0};
    
    for (int mask = 1 ; mask < (1 << n) ; ++mask) {
        dp[mask] = {n + 1, 0}; 
        
        for (int p = 0 ; p < n ; ++p) {
           
            if (mask & (1 << p)) {
                int prev_mask = mask ^ (1 << p);
                pair<int, int> option = dp[prev_mask];
                
                if (option.second + weight[p] <= w) {
                    option.second += weight[p];
                } 
				else {
                    option.first++;
                    option.second = weight[p];
                }
                
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    
    cout << dp[(1 << n) - 1].first << '\n';
    
    return 0;
}
