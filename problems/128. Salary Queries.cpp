#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> poc(n);
    vector<int> a(n);
    a.reserve(n + q);
    
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        poc[i] = a[i];
    }   
    
    vector<tuple<char, int, int>> query;
    query.reserve(q);
    
    while(q--){
        char c;
        cin >> c;
        int a1, b1;
        cin >> a1 >> b1;
                
        if(c == '!'){           
            a.push_back(b1);
        }
        
        query.push_back(make_tuple(c, a1, b1));
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int indeks = a.size();
    int size = 1;
    while(size < indeks) size <<= 1;
    
    vector<int> segment(size * 2, 0);
    
    auto get_idx = [&](int val) {
        return lower_bound(a.begin(), a.end(), val) - a.begin();
    };
    
    for(auto &x : poc){
        segment[size + get_idx(x)]++;
    }
    
    for(int i = size - 1 ; i > 0 ; --i){
        segment[i] = segment[i * 2] + segment[i * 2 + 1];
    }
    
    for(auto &x : query){
        char c = get<0>(x);
        int a1 = get<1>(x);
        int b1 = get<2>(x);
        
        if(c == '?'){
            int left = get_idx(a1); 
            int right = upper_bound(a.begin(), a.end(), b1) - a.begin() - 1; 
            
            int ans = 0;
            
            if(left <= right) {
                left += size;
                right += size;
                
                while(left <= right){
                    if(left % 2 == 1) ans += segment[left++];
                    if(right % 2 == 0) ans += segment[right--]; 
                    
                    left /= 2;
                    right /= 2;
                }
            }
            cout << ans << "\n";
        }
        else{
            int idx1 = get_idx(poc[a1 - 1]) + size;
            int idx2 = get_idx(b1) + size;
            segment[idx1]--;
            segment[idx2]++;
            
            for(idx1 /= 2 ; idx1 > 0 ; idx1 /= 2){
                segment[idx1] = segment[idx1 * 2] + segment[idx1 * 2 + 1];
            }
            
            for(idx2 /= 2 ; idx2 > 0 ; idx2 /= 2){
                segment[idx2] = segment[idx2 * 2] + segment[idx2 * 2 + 1];
            }
            
            poc[a1 - 1] = b1; 
        }
    }
    
    return 0;
}
