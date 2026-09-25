#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, long long b){
    long long res = 1;
	a %= MOD;
	
    while(b){
        if(b & 1){
        	res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD; 
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1 ; i <= n ; ++i) {
        cin >> p[i];
    }

    vector<int> spf(n + 1);
    for (int i = 1 ; i <= n ; ++i) spf[i] = i;
    
    for (int i = 2 ; i * i <= n ; ++i){
        if (spf[i] == i){
            for (int j = i * i; j <= n; j += i){
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    vector<bool> vis(n + 1, false);
    vector<int> max_pow(n + 1, 0);

    for (int i = 1 ; i <= n ; ++i){
        if (!vis[i]){
            int curr = i;
            int length = 0;
            
            while (!vis[curr]) {
                vis[curr] = true;
                curr = p[curr];
                length++;
            }

            int temp = length;
            while (temp > 1) {
                int prime = spf[temp];
                int count = 0;
                while (temp % prime == 0) {
                    count++;
                    temp /= prime;
                }
                max_pow[prime] = max(max_pow[prime], count);
            }
        }
    }

    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (max_pow[i] > 0) {
            ans = (ans * power(i, max_pow[i])) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}
