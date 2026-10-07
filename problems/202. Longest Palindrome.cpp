#include<bits/stdc++.h>

using namespace std;

vector<int> manacher(string s){
    string t = "#";
    for(char c : s) {
        t += c;
        t += "#";
    }
    
    int n = t.length();
    vector<int> p(n, 0);
    int c = 0;
    int r = 0;
    
    for(int i = 0 ; i < n ; ++i){
        int mirror = 2 * c - i;
        
        if (i < r) {
            p[i] = min(r - i, p[mirror]);
        }
        
        while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && t[i - 1 - p[i]] == t[i + 1 + p[i]]) {
            p[i]++;
        }
        
        if (i + p[i] > r){
            c = i;
            r = i + p[i];
        }
    }
    
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    vector<int> res = manacher(s);
    
    int max_len = 0;
    int best_center = 0;
    
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] > max_len) {
            max_len = res[i];
            best_center = i;
        }
    }
    
    int start_idx = (best_center - max_len) / 2;
    cout << s.substr(start_idx, max_len) << "\n";
    
    return 0;
}
