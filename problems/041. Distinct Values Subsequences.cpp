#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    map<int, int> freq;
    for (int i = 0 ; i < n ; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    long long ans = 1;
    for (auto &pair : freq) {
        ans = (ans * (pair.second + 1)) % MOD;
    }
    
    ans = (ans - 1 + MOD) % MOD;
    
    cout << ans << "\n";
    
    return 0;
}
