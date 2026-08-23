#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
        
    vector<long long> array(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> array[i];
    }
    
    int size = 1;
    while(size < n) size <<= 1;
    
    vector<pair<long long, long long>> segment(2 * size, {0LL, 0LL});
    
    for(int i = 0 ; i < n ; ++i){
        segment[i + size].first = array[i];
        segment[i + size].second = max(0LL, array[i]);
    }
    
    for(int i = size - 1 ; i > 0 ; --i){
        segment[i].first = segment[i * 2].first + segment[i * 2 + 1].first;
        segment[i].second = max(segment[i * 2].second, segment[i * 2].first + segment[i * 2 + 1].second);
    }
    
    while(q--){
        int type, a, b;
        cin >> type >> a >> b;
        
        if(type == 1){
            --a;
            a += size;
            segment[a].first = b;
            segment[a].second = max(0LL, (long long)b);
            
            for(a /= 2 ; a > 0 ; a /= 2){
                segment[a].first = segment[a * 2].first + segment[a * 2 + 1].first;
                segment[a].second = max(segment[a * 2].second, segment[a * 2].first + segment[a * 2 + 1].second);
            }
        }
        else{
            --a;
            --b;
            a += size;
            b += size;
            
            pair<long long, long long> left_res = {0, 0};
            pair<long long, long long> right_res = {0, 0};
            
            while(a <= b){
                if(a % 2 == 1){
                    left_res.second = max(left_res.second, left_res.first + segment[a].second);
                    left_res.first += segment[a].first;
                    a++;
                }
                if(b % 2 == 0){
                    right_res.second = max(segment[b].second, segment[b].first + right_res.second);
                    right_res.first += segment[b].first;
                    b--;
                }
                a /= 2;
                b /= 2;
            }
            
            long long ans = max(left_res.second, left_res.first + right_res.second);
            cout << ans << "\n";
        }
    }
    
    return 0;
}
