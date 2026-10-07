#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    
    s += s; 

    int i = 0;
    int j = 1;

    while (i < n && j < n) {
        int k = 0;
        
        while (k < n && s[i + k] == s[j + k]) {
            k++;
        }
        
        if (k == n) {
            break;
        }

        if (s[i + k] > s[j + k]) i = max(i + k + 1, j + 1);
		else j = max(j + k + 1, i + 1);
        
    }

    int start_idx = min(i, j);    
    cout << s.substr(start_idx, n) << "\n";

    return 0;
}
