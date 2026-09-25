#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> factorials (21);
    factorials[0] = 1;
    factorials[1] = 1;
    
    for (int i = 2 ; i <= 20 ; ++i){
        factorials[i] = factorials[i - 1] * i;
    }
    
    int t;
    cin >> t;
    
    while (t--){
        int type, n;
	    cin >> type >> n;
	    
	    if (type == 1){
	        long long k;
	        cin >> k;
	        k--; 
	        
	        vector<int> available;
	        for (int i = 1 ; i <= n ; ++i){
	            available.push_back(i);
	        }
	        
	        for (int i = n - 1; i >= 0; --i){
	            int idx = k / factorials[i]; 
	            
	            cout << available[idx] << ' ';
	            available.erase(available.begin() + idx); 

	            k %= factorials[i]; 
	        }
	        
	    } 
		else{
			
	        long long k = 0;
	        
	        vector<int> available;
	        for (int i = 1 ; i <= n ; ++i){
	            available.push_back(i);
	        }
	        
	        for (int i = n - 1; i >= 0; --i) {
	            int val;
	            cin >> val;
	            
	            int idx = find(available.begin(), available.end(), val) - available.begin();
	            k += idx * factorials[i];
	            
	            available.erase(available.begin() + idx);
	        }
	        
	        cout << k + 1;
	    }
	    
	    cout << "\n";
    }
    
    
    return 0;
}
