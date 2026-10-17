#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> moves (k);
	
	for(int i = 0 ; i < k ; ++i){
		cin >> moves[i];
	}
	
	vector<bool> dp (n + 1, false);
	
	for(int i = 1 ; i <= n ; ++i){
		for(auto &move : moves){
			if(i - move >= 0 && !dp[i - move]){
				dp[i] = true;
			}
		}
	}
	
	for(int i = 1 ; i <= n ; ++i){
		if(dp[i]) cout << "W";
		else cout << "L";
	}
	
	cout << "\n";
	return 0;
}
