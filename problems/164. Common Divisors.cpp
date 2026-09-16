#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> sort (MAX + 1, 0);
    
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        sort[x]++;
    }
    
    for(int i = MAX; i >= 1; --i){
        int count = 0;
        
        for(int j = i; j <= MAX; j += i){
            count += sort[j];
        
            if(count >= 2){
                cout << i << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}
