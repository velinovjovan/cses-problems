#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> segment(2 * n, 0);

    for(int i = n; i < 2 * n; ++i){
        cin >> segment[i];
    }

    for(int i = n - 1; i > 0; --i){
        segment[i] = segment[2 * i] + segment[2 * i + 1];
    }

    while(q--){
        int c, a, b;
        cin >> c >> a >> b;

        if(c == 2){
            a--;
            b--;
            
            a += n;
            b += n;

            long long ans = 0;

            while(a <= b){
                if(a % 2 == 1){
                    ans += segment[a];
                    ++a;
                }
                if(b % 2 == 0){
                    ans += segment[b];
                    --b;
                }
                a /= 2;
                b /= 2;
            }

            cout << ans << '\n';
        }
        else {
            a--;
            
            a += n;
            segment[a] = b;

            for(a /= 2; a > 0; a /= 2){
                segment[a] = segment[2 * a] + segment[2 * a + 1];
            }
        }
    }
    
    return 0;
}
