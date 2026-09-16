#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<long long> val(n);
    vector<long long> sorted(n);
    
    for(int i = 0 ; i < n ; ++i){
        cin >> val[i];
        sorted[i] = val[i];
    }
    
    sort(sorted.begin(), sorted.end());
    map<long long, int> mapa;
    map<int, long long> invmapa;
    
    int br = 1;
    for(auto &x : sorted){
        if(mapa[x] == 0){
            mapa[x] = br;
            invmapa[br] = x;
            br++;
        }
    }
    
    int size = 1;
    while(size < n) size <<= 1; 
    
    vector<int> segment(size * 2, 0);
    
    for(int i = 0 ; i < k ; ++i){
        segment[size + mapa[val[i]] - 1]++;
    }
    
    for(int i = size - 1 ; i > 0 ; --i){
        segment[i] = segment[i * 2] + segment[i * 2 + 1];
    }
    
    for(int i = k ; i < n ; ++i){
        int target = (k + 1) / 2;
        
        int j = 1;
        while(j < size){
            if(segment[j * 2] >= target){
                j = j * 2;
            }
            else{
                target -= segment[j * 2];
                j = j * 2 + 1;
            }
        }
        
        cout << invmapa[j - size + 1] << ' ';
        
        int idx_remove = size + mapa[val[i - k]] - 1;
        segment[idx_remove]--;
        
        for(idx_remove /= 2 ; idx_remove > 0 ; idx_remove /= 2){
            segment[idx_remove] = segment[idx_remove * 2] + segment[idx_remove * 2 + 1];
        }
        
        int idx_add = size + mapa[val[i]] - 1;
        segment[idx_add]++;
        
        for(idx_add /= 2 ; idx_add > 0 ; idx_add /= 2){
            segment[idx_add] = segment[idx_add * 2] + segment[idx_add * 2 + 1];
        }
    }
    
    int target = (k + 1) / 2;
    int j = 1;
    while(j < size){
        if(segment[j * 2] >= target){
            j = j * 2;
        }
        else{
            target -= segment[j * 2];
            j = j * 2 + 1;
        }
    }
        
    cout << invmapa[j - size + 1] << '\n';
        
    return 0;
}
