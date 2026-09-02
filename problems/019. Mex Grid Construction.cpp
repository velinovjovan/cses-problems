#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int row = 0 ; row < n ; ++row){
		for(int col = 0 ; col < n ; ++col){
			cout << (row ^ col) << ' ';
		}
		
		cout << '\n';
	}
	
	
	return 0;
}
