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
    
    vector<int> count_seg(size * 2, 0);
    vector<long long> sum_seg(size * 2, 0LL);
    
    for(int i = 0 ; i < k ; ++i){
        int idx = size + mapa[val[i]] - 1;
        count_seg[idx]++;
        sum_seg[idx] += val[i];
    }
    
    for(int i = size - 1 ; i > 0 ; --i){
        count_seg[i] = count_seg[i * 2] + count_seg[i * 2 + 1];
        sum_seg[i] = sum_seg[i * 2] + sum_seg[i * 2 + 1];
    }
    
    for(int i = k ; i <= n ; ++i){
        int target = (k + 1) / 2;
        int j = 1;
        long long left_sum = 0;
        
        while(j < size){
            if(count_seg[j * 2] >= target){
                j = j * 2;
            }
            else{
                target -= count_seg[j * 2];
                left_sum += sum_seg[j * 2]; 
                j = j * 2 + 1;
            }
        }
        
        long long median = invmapa[j - size + 1];
        
        left_sum += 1LL * target * median; 
        
        long long total_sum = sum_seg[1];
        long long right_sum = total_sum - left_sum;
        
        long long L = (k + 1) / 2;
        long long R = k - L;
        
        long long cost = (L * median - left_sum) + (right_sum - R * median);
        cout << cost << ' ';
        
        if (i == n) break; 
        
        int idx_remove = size + mapa[val[i - k]] - 1;
        count_seg[idx_remove]--;
        sum_seg[idx_remove] -= val[i - k];
        
        for(idx_remove /= 2 ; idx_remove > 0 ; idx_remove /= 2){
            count_seg[idx_remove] = count_seg[idx_remove * 2] + count_seg[idx_remove * 2 + 1];
            sum_seg[idx_remove] = sum_seg[idx_remove * 2] + sum_seg[idx_remove * 2 + 1];
        }
        
        int idx_add = size + mapa[val[i]] - 1;
        count_seg[idx_add]++;
        sum_seg[idx_add] += val[i];
        
        for(idx_add /= 2 ; idx_add > 0 ; idx_add /= 2){
            count_seg[idx_add] = count_seg[idx_add * 2] + count_seg[idx_add * 2 + 1];
            sum_seg[idx_add] = sum_seg[idx_add * 2] + sum_seg[idx_add * 2 + 1];
        }
    }
    
    return 0;
}
