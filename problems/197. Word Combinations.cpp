#include <bits/stdc++.h>

using namespace std;

const long long A = 313; 
const long long B = 1e9 + 9; 
const int mod = 1e9 + 7;

long long get_hash(int l, int r, const vector<long long>& hesh, const vector<long long>& p) {
    long long h = hesh[r];
    if (l > 0) {
        h = (h - (hesh[l - 1] * p[r - l + 1]) % B + B) % B;
    }
    return h;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    vector<long long> p(n);
    vector<long long> hesh(n);
    
    p[0] = 1;
    hesh[0] = s[0];
    
    for(int i = 1; i < n; ++i){
        p[i] = (p[i - 1] * A) % B;
        hesh[i] = (hesh[i - 1] * A + s[i]) % B;
    }
    
    int k;
    cin >> k;
    
    unordered_map<int, unordered_set<long long>> valid_hashes;
    vector<int> distinct_lengths;
    
    for(int i = 0 ; i < k ; ++i){
        string temp;
        cin >> temp;
        
        long long current_hash = 0;
        for(char c : temp) {
            current_hash = (current_hash * A + c) % B;
        }
        
        if (valid_hashes[temp.length()].empty()) {
            distinct_lengths.push_back(temp.length());
        }
        valid_hashes[temp.length()].insert(current_hash);
    }
    
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; ++i){
        if(dp[i] == 0) continue; 
        
        for(int len : distinct_lengths){
            if(i + len <= n){
                long long sub_hash = get_hash(i, i + len - 1, hesh, p);
                
                if(valid_hashes[len].count(sub_hash)){
                	dp[i + len] += dp[i];
                	dp[i + len] %= mod;
                }
            }
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
