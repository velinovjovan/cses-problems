#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("popcnt,avx2")

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    vector<bitset<3000>> a[26];
    
    for(int q = 0; q < 26; ++q){
        a[q].resize(n);
    }

    for(int i = 0; i < n; ++i){
        cin >> grid[i];
        for (int j = 0; j < n; ++j){
            a[grid[i][j] - 'A'][i].set(j);
        }
    }

    for(int q = 0; q < k; ++q){
        bool ans = false;
        
        for(int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
            	
                int count = (int)(a[q][i] & a[q][j]).count();
                
				if(count > 1) {
                    ans = true;
                    break;
                }
            }
            if(ans) break;
        }

        if(ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";
    }

    return 0;
}
