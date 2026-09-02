#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > (n + 1) / 2) {
            cout << -1 << "\n";
            return 0;
        }
    }

    string result = "";
    char prev = '#';

    for (int i = 0; i < n; ++i) {
        int rem_len = n - i;
        bool placed = false;

        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0 || (prev == (char)('A' + c))) {
                continue;
            }

            freq[c]--;

            bool valid = true;
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > rem_len / 2) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result += (char)('A' + c);
                prev = (char)('A' + c);
                placed = true;
                break;
            }

            freq[c]++;
        }

        if (!placed) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << result << "\n";
    
    
    return 0;
}
