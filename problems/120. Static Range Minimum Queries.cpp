#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}	
	
	int najveci = 0;
	int temp = n;
	
	while(temp > 0){
		najveci++;
		temp >>= 1;
	}
	
	vector<vector<int>> dp (najveci, vector<int> (n));
	
	for(int i = 0 ; i < n ; ++i){
		dp[0][i] = a[i];
	}
	
	for(int i = 1 ; i < najveci ; ++i){
		for(int j = 0 ; j + (1 << i) <= n ; ++j){
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
		}
	}
	
	while(q--){
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		
		int razlika = b - a + 1;
		int stepen = -1;
		
		while(razlika > 0){
			stepen ++;
			razlika >>= 1;
		}
		
		cout << min(dp[stepen][a], dp[stepen][b - (1 << stepen) + 1]) << "\n";
	}
	
	
	return 0;
}
