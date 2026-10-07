#include <bits/stdc++.h>

using namespace std;

vector<int> manacher_all_palindromes(string s) {
    string t = "#";
    for(char c : s) {
        t += c;
        t += "#";
    }
    
    int n = t.length();
    vector<int> p(n, 0); 
    int c = 0; 
    int r = 0; 
    
    for(int i = 0 ; i < n ; ++i) {
        int mirror = 2 * c - i;
        
        if (i < r) {
            p[i] = min(r - i, p[mirror]);
        }
    	
        while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && t[i - 1 - p[i]] == t[i + 1 + p[i]]) {
            p[i]++;
        }
        
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    
    int orig_n = s.length();
    vector<int> ans(orig_n, 1);

    for (int i = 0; i < n; ++i) {
        if (p[i] > 0) {
            int start_idx = (i - p[i]) / 2;
            int end_idx = start_idx + p[i] - 1;
            ans[end_idx] = max(ans[end_idx], p[i]);
        }
    }

    for (int i = orig_n - 1; i >= 1; --i) {
        ans[i - 1] = max(ans[i - 1], ans[i] - 2);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    vector<int> res = manacher_all_palindromes(s);
        
    
    for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    
	cout << "\n";
    
    return 0;
}
