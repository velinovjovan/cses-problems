#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<long long> val(n);
    
    for(int i = 0 ; i < n ; ++i){
        cin >> val[i];
    }
    
    set<long long> skup;
    for(int i = 0 ; i <= k ; ++i) {
        skup.insert(i);
    }
    
    vector<int> freq (k + 1, 0);
    
    for(int i = 0 ; i < k ; ++i){
        if(val[i] <= k){
            freq[val[i]]++;
            if(freq[val[i]] == 1){
                skup.erase(val[i]);
            }
        }
    }
    
    for(int i = k ; i < n ; ++i){
        cout << *skup.begin() << ' ';
        
        long long left_val = val[i - k];
        long long right_val = val[i];
        
        if(left_val <= k) {
            freq[left_val]--;
            if(freq[left_val] == 0) {
                skup.insert(left_val);
            }
        }
        
        if(right_val <= k) {
            freq[right_val]++;
            if(freq[right_val] == 1) {
                skup.erase(right_val);
            }
        }
    }
    cout << *skup.begin() << '\n';
    
    return 0;    
}
