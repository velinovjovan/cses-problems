#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string res = "";
    res += grid[0][0];
    
    vector<int> active = {0};

    for (int k = 0; k < 2 * n - 2; k++) {
        char min_char = 'Z' + 1;

        for (int r : active) {
            int c = k - r;
            if (r + 1 < n) {
                min_char = min(min_char, grid[r + 1][c]);
            }
            if (c + 1 < n) {
                min_char = min(min_char, grid[r][c + 1]);
            }
        }

        res += min_char;

        vector<int> next_active;
        vector<bool> seen(n, false);

        for (int r : active) {
            int c = k - r;
            
            if (r + 1 < n && grid[r + 1][c] == min_char) {
                if (!seen[r + 1]) {
                    seen[r + 1] = true;
                    next_active.push_back(r + 1);
                }
            }
            
            if (c + 1 < n && grid[r][c + 1] == min_char) {
                if (!seen[r]) {
                    seen[r] = true;
                    next_active.push_back(r);
                }
            }
        }

        active = move(next_active);
    }

    cout << res << "\n";
    
    return 0;
}
