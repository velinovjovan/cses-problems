#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	unordered_map<int,int> pos;
	pos[0] = 0;
	
	int temp;
	for(int i = 1; i <= n ; ++i){
		cin >> temp;
		pos[temp] = i;
	}
	
	int ans = 1;
	
	for(int i = 1 ; i <= n ; ++i){
		if(pos[i] < pos[i - 1]) ans++;
	}
	
	cout << ans;
	
	
	return 0;

}
