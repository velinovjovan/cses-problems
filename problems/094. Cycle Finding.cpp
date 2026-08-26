#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int,int,int>> edges;
    
    for(int i = 0 ; i < m ; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_tuple(a, b, c));
    }

    vector<long long> distances(n + 1, 0); 
    vector<int> parent(n + 1, -1);
    
    int last = -1;
    
    for(int i = 0 ; i < n ; ++i){
        last = -1;
        for(auto &x : edges){
            int a, b, w;
            tie(a, b, w) = x;
            
            if(distances[b] > distances[a] + w){
                distances[b] = distances[a] + w;
                parent[b] = a;
				last = b;
            }
        }
    }
    
    if(last == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        
        for(int i = 0; i < n; ++i){
            last = parent[last];
        }

		vector<int> cycle;
        int fn = last;
        
        cycle.push_back(last);
        last = parent[last];
        
        while(last != fn){
            cycle.push_back(last);
            last = parent[last];
        }
        
        cycle.push_back(last);
        reverse(cycle.begin(), cycle.end());
        
        for(int v : cycle){
            cout << v << ' ';
        }
    }
    
    return 0;
}
