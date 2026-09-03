#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    map<int, int> freq;
    int i = 0;
    long long ans = 0;
    
    for(int j = 0; j < n; ++j) {
        freq[a[j]]++;
        
        while(freq.size() > k) {
            freq[a[i]]--;
            if(freq[a[i]] == 0) {
                freq.erase(a[i]);
            }
            ++i;
        }
        
        ans += (j - i + 1);
    }
    
    cout << ans << "\n";
    
    return 0;
}
