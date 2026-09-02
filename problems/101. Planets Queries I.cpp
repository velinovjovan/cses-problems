#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    int size = 30; 
    
    vector<vector<int>> sparse(size, vector<int>(n + 1));
    
    for(int i = 1; i <= n; ++i){
        cin >> sparse[0][i];
    }

    for(int i = 1; i < size; ++i){
        for(int j = 1; j <= n; ++j){
            sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
        }
    }
    
    while(q--){
        int x, k;
        cin >> x >> k;
        
        int vel = 0;
        while(k){
            if(k & 1){
                x = sparse[vel][x];
            }
            
            vel++;
            k >>= 1;
        }
        
        cout << x << "\n";
    }
    
    return 0;
}
