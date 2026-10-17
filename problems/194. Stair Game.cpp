#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int res {0};
		
		int temp;
		for(int i = 0 ; i < n ; ++i){
			cin >> temp;
			
			if(i & 1){
				res ^= temp;
			}
		}
		
		if(res) cout << "first" << "\n";
		else cout << "second" << "\n";
	}
	
	
	return 0;
}
