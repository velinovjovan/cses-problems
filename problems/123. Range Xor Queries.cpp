#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    
    vector<int> dp(n + 1, 0); 
    
    for(int i = 0 ; i < n ; ++i){
        dp[i + 1] = dp[i] ^ a[i];
    }
    
    while(q--){
        int L, R;
        cin >> L >> R;
        --L;
        --R;

        cout << (dp[R + 1] ^ dp[L]) << "\n"; 
    }
    
    return 0;
}
