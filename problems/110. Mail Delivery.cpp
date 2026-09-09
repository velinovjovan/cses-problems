#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
	cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    
    for(int i = 0 ; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        
        degree[a]++;
        degree[b]++;
            
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    
    for(int i = 1 ; i <= n ; ++i){
        if(degree[i] % 2 != 0){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    
    vector<int> circuit;
    vector<int> stek; 
    vector<bool> edge_used(m, false);
    
    stek.push_back(1);
    
    while(!stek.empty()){
        int u = stek.back();
        bool found_edge = false;
        
        while(!adj[u].empty()){
        	int v, edge_idx;
        	tie(v, edge_idx) = adj[u].back();
            adj[u].pop_back();
            
            if(!edge_used[edge_idx]){
                edge_used[edge_idx] = true;
                stek.push_back(v);
                found_edge = true;
                break;
            }
        }
        
        if(!found_edge){
            circuit.push_back(u);
            stek.pop_back();
        }
    }
    
    if(circuit.size() != m + 1){
        cout << "IMPOSSIBLE\n";
    } 
	else {
		reverse(circuit.begin(), circuit.end()); // optional
        for(int i = 0 ; i < circuit.size() ; ++i){
            cout << circuit[i] << ' ';
        }
        cout << "\n";
    }
    
    return 0;
}
