#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    int size = 1;
    while (size < n) size <<= 1;
    
    vector<int> seg(2 * size, 0);
    
    for (int i = 0; i < n; ++i) {
        seg[size + i] = 1;
    }

    for (int i = size - 1; i >= 1; --i) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
    
    int curr = 0;
    for (int j = 0; j < n; ++j) {
        int remaining = n - j;
        curr = (curr + k) % remaining;
        
        int idx = 1;
        int target = curr + 1;
        
        while (idx < size) {
            if (seg[2 * idx] >= target) {
                idx = 2 * idx;
            } else {
                target -= seg[2 * idx];
                idx = 2 * idx + 1;
            }
        }
        
        cout << (idx - size + 1) << ' ';
        
        seg[idx] = 0;
        int a = idx / 2;
        while (a >= 1) {
            seg[a] = seg[2 * a] + seg[2 * a + 1];
            a /= 2;
        }
    }
    
    
    cout << "\n";
    
    return 0;
}
