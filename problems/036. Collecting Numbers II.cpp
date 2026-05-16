#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> pos;
    pos[0] = 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        if (i > j) swap(i, j);

        int x = a[i];
        int y = a[j];

        if (pos[x + 1] > i && pos[x + 1] < j) rounds++;
        if (pos[x - 1] > i && pos[x - 1] < j) rounds--;
        if (pos[y + 1] > i && pos[y + 1] < j) rounds--;
        if (pos[y - 1] > i && pos[y - 1] < j) rounds++;

        if (x == (y + 1)) rounds--;  
        if (x == (y - 1)) rounds++; 

        cout << rounds << '\n';
        
        swap(a[i], a[j]);
        pos[x] = j;
        pos[y] = i;
    }
    
    
    return 0;
    
}
