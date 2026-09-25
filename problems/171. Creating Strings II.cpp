#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b){
    long long ans = 1;
    a %= mod;
    
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    
    return ans;
}

long long divide(long long a, long long b){
    return (a * power(b, mod - 2)) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    long long gore = 1; 
    long long dole = 1;
    long long curr = 1;
    long long j = 2;
    
    for(int i = 1 ; i < s.length() ; ++i){
        if(s[i] == s[i - 1]){
            curr *= j;
            curr %= mod;
            ++j;
        }
        else{
            dole *= curr;
            dole %= mod;
            j = 2;
            curr = 1;
        }
        gore *= (i + 1);
        gore %= mod;
    }
    dole = (dole * curr) % mod; 

    cout << divide(gore, dole) << "\n"; 
    
    return 0;
}
