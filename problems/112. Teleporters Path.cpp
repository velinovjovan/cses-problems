#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj (n + 1);
    vector<int> indegree (n + 1, 0);
    vector<int> outdegree (n + 1, 0);
    
    for(int i = 0 ; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back({b, i});
        outdegree[a]++;
        indegree[b]++;
    }
    
    bool possible = true;
    if(outdegree[1] - indegree[1] != 1) possible = false;
    if(indegree[n] - outdegree[n] != 1) possible = false;
    
    for(int i = 2 ; i <= n - 1 ; ++i){
        if(indegree[i] != outdegree[i]){
            possible = false;
            break;
        }
    }
    
    if(!possible){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> circuit;
    vector<int> stek;
    vector<bool> edge_used (m, false);
    stek.push_back(1);
    
    while(!stek.empty()){
        int u = stek.back();
        bool has_edge = false;
        
        while(!adj[u].empty()){
            int v, edgeidx;
            tie(v, edgeidx) = adj[u].back();
            adj[u].pop_back();
            
            if(!edge_used[edgeidx]){
                edge_used[edgeidx] = true;
                stek.push_back(v);
                has_edge = true;
                break;
            }
        }
        
        if(!has_edge){
            circuit.push_back(u);
            stek.pop_back();
        }
    }
    
    if(circuit.size() != m + 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    reverse(circuit.begin(), circuit.end());
    
    for(auto x : circuit){
    	cout << x << ' ';
	}
    cout << "\n";
    
    return 0;
}
