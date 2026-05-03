#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	int x,y;
	while(t--){
		cin >> x >> y;
		
		if((x+y) % 3 == 0 && min(x,y)*2 >= max(x,y)) cout << "YES\n"; 
		else cout << "NO\n";
	}
	
	
	return 0;
	
}
