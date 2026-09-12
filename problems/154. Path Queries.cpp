#include <iostream>
#include <vector>

using namespace std;

vector<int> ss_size;
vector<int> id;

void dfs(const vector<vector<int>> &adj, int node, int prev, int &timer) {
    id[node] = timer++;
    ss_size[node] = 1;
    
    for (auto &x : adj[node]) {
        if (x != prev) {
            dfs(adj, x, node, timer);
            ss_size[node] += ss_size[x];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    vector<long long> value(n);
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    ss_size.resize(n);
    id.resize(n);
    int timer = 0;
    dfs(adj, 0, -1, timer);
    
    int size = 1;
    while (size <= n) {
        size <<= 1;
    }
    
    vector<long long> diff_arr(n + 1, 0);
    
    for (int i = 0 ; i < n ; ++i) {
        diff_arr[id[i]] += value[i];
        diff_arr[id[i] + ss_size[i]] -= value[i];
    }
    
    vector<long long> segment(size * 2, 0);
    for (int i = 0 ; i <= n ; ++i) {
        segment[size + i] = diff_arr[i];
    }
    
    for (int i = size - 1 ; i > 0 ; --i) {
        segment[i] = segment[i * 2] + segment[i * 2 + 1];
    }
    
    auto update_point = [&](int pos, long long diff) {
        if (pos > n) return;
        int idx = size + pos;
        segment[idx] += diff;
        for (idx /= 2; idx > 0; idx /= 2) {
            segment[idx] = segment[idx * 2] + segment[idx * 2 + 1];
        }
    };
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            --s;
            
            long long diff = x - value[s];
            value[s] = x; 
            
            update_point(id[s], diff);
            update_point(id[s] + ss_size[s], -diff);
        } else {
            int s;
            cin >> s;
            --s;
            
            int a = size;
            int b = size + id[s];
            
            long long ans = 0;
            while (a <= b) {
                if (a % 2 == 1) ans += segment[a++];
                if (b % 2 == 0) ans += segment[b--];
                a /= 2;
                b /= 2;
            }
            
            cout << ans << "\n";
        }
    }
    
    return 0;
}
