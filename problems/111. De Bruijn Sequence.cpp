#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if(n == 1){
        cout << "01" << "\n";
        return 0;
    } 
    
    vector<vector<pair<int,int>>> adj (1 << (n - 1));
    int mask = (1 << (n - 1)) - 1; 
    
    for(int i = 0 ; i < (1 << (n - 1)) ; ++i){
        int a = (i << 1) | 1;
        int b = (i << 1) | 0;
        
        a = a & mask;
        b = b & mask;
        
        adj[i].push_back({a, i});
        adj[i].push_back({b, (1 << (n - 1)) + i});
    }
    
    string ans = ""; 
    vector<int> stek;
    vector<bool> edge_used (2 * (1 << (n - 1)), false);
    stek.push_back(0);
    
    while(!stek.empty()){
        int u = stek.back();
        bool found_edge = false;
        
        while(!adj[u].empty()){
            int node, edgeId;
            tie(node, edgeId) = adj[u].back();
            adj[u].pop_back();
            
            if(!edge_used[edgeId]){
                edge_used[edgeId] = true;
                stek.push_back(node);
                found_edge = true;
                break;
            }
        }
        
        if(!found_edge){
            ans += (char)((u & 1) + '0'); 
            stek.pop_back();
        }
    }
    
    reverse(ans.begin(), ans.end());

    string final_ans = string(n - 1, '0') + ans.substr(1);
    
    cout << final_ans << "\n";
    
    return 0;
}
