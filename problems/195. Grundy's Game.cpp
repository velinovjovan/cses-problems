#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
int grundy[MAXN];

void precompute(){
    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 0;
    
    for (int i = 3 ; i < MAXN ; ++i) {
        vector<bool> seen (MAXN, false);
        
        for (int j = 1; j <= i / 2; ++j){
            if (j != i - j){
            	
                int val = grundy[j] ^ grundy[i - j];
                if (val < MAXN) seen[val] = true;
            }
        }
        
        for (int mex = 0; mex < MAXN; ++mex) {
            if (!seen[mex]) {
                grundy[i] = mex;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n >= MAXN || grundy[n] != 0) cout << "first" << "\n";
		else cout << "second" << "\n";
    }
    
    return 0;
}
