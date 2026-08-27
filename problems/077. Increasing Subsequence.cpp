#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }    
    
    vector<int> tails;
    
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), a[i]);
        
        if (it == tails.end()) {
            tails.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    
    cout << tails.size() << "\n";
    
    return 0;
}
