#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    vector<long long> t (n);
 
    for (int i = 0 ; i < n ; ++i) {
        cin >> t[i];
    }
 
    unordered_map<long long, long long>  mapa;
    mapa.reserve(1 << (n / 2));
 
    for (int i = 0 ; i < (1 << (n/2)) ; ++i) {
        int num = i;
 
        long long sum = 0;
        int j = 0;
        while (num) {
            if (num & 1) {
                sum += t[j];
            }
            ++j;
            num >>= 1;
        }
 
        mapa[sum] ++;
    }
 
    long long ans = 0;
 
    for (int i = 0 ; i < (1 << ((n + 1)/2)) ; ++i) {
        int num = i;
 
        long long sum = 0;
        int j = n / 2;
        while (num) {
            if (num & 1) {
                sum += t[j];
            }
            ++j;
            num >>= 1;
        }
 
        ans += mapa[x - sum];
    }
 
    cout << ans << "\n";
 
 
    return 0;
}
