#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    vector<bitset<32>> a (n);
 
    for (int i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }
 
    int ans = numeric_limits<int>::max();
    for (int i = 0 ; i < n - 1 ; ++i) {
        for (int j = i + 1 ; j < n ; ++j) {
            int curr = (int)(a[i] ^ a[j]).count();
            ans = min(ans, curr);
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
