#include <bits/stdc++.h>

using namespace std;

const long long A = 313;
const long long B = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    vector<long long> hash(n);
    vector<long long> p(n);
    
    hash[0] = s[0];
    p[0] = 1;
    
    for(int i = 1; i < n; ++i){
        hash[i] = (hash[i - 1] * A + s[i]) % B;
        p[i] = (p[i - 1] * A) % B;
    }
    
    auto get_hash = [&](int l, int r) {
        if (l == 0) return hash[r];
        long long h = (hash[r] - (hash[l - 1] * p[r - l + 1]) % B + B) % B;
        return h;
    };
    
    for(int k = 1 ; k <= n ; ++k){
        int len = n - k;
        
        if (len == 0) cout << k << " ";
		else{
            if(get_hash(0, len - 1) == get_hash(k, n - 1)) {
                cout << k << " ";
            }
        }
    }
    cout << "\n";
    
    
    return 0;

}
