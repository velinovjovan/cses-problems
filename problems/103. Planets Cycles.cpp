#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n + 1);
    for(int i = 1 ; i <= n ; ++i){
        cin >> t[i];
    }

    vector<int> ans(n + 1, 0);
    vector<bool> visited(n + 1, false);

    for(int i = 1 ; i <= n ; ++i){
        if (ans[i] != 0) continue;

        vector<int> path;
        int curr = i;

        while(!visited[curr]){
            visited[curr] = true;
            path.push_back(curr);
            curr = t[curr];
        }

        int path_len = path.size();
        int cycle_start = -1;

        for(int j = 0 ; j < path_len ; ++j){
            if (path[j] == curr){
                cycle_start = j;
                break;
            }
        }

        if(cycle_start != -1){
        	
            int cycle_length = path_len - cycle_start;   
            for (int j = cycle_start ; j < path_len ; ++j){
                ans[path[j]] = cycle_length;
            }
            
          
            int dist = cycle_length;
            for (int j = cycle_start - 1 ; j >= 0 ; --j){
                dist++;
                ans[path[j]] = dist;
            }
        }
		else{
            int dist = ans[curr];
            
            for (int j = path_len - 1 ; j >= 0 ; --j){
                dist++;
                ans[path[j]] = dist;
            }
        }
    }

    for (int i = 1 ; i <= n ; ++i) {
        cout << ans[i] << ' ';
    }
    cout << "\n";

    return 0;
}
