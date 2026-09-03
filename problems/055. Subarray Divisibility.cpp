#include<bits/stdc++.h> 
 
using namespace std; 
 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int n; 
    cin >> n; 
 
    vector<int> a(n); 
     
    for(int i = 0; i < n; ++i){ 
        cin >> a[i]; 
    } 
 
    long long prefix_sum = 0; 
    long long ans = 0; 
    vector<long long> sums(n); 
 
    sums[0] = 1;
     
    for(auto &val : a) { 
        prefix_sum += val; 
        prefix_sum = (prefix_sum % n + n) % n; 
 
        ans += sums[prefix_sum];
        sums[prefix_sum]++;
    } 
     
    cout << ans << "\n"; 
     
    return 0; 
}
