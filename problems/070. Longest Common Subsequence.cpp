#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr1 (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> arr1[i];
	}
	
	vector<int> arr2 (m);
	
	for(int i = 0 ; i < m ; ++i){
		cin >> arr2[i];
	}
	
	vector<vector<int>> dp (n + 1, vector<int> (m + 1));
	vector<vector<pair<int,int>>> parent (n + 1, vector<pair<int,int>> (m + 1));
	
	for(int i = 1 ; i < n + 1 ; ++i){
		for(int j = 1 ; j < m + 1 ; ++j){
			if(arr1[i - 1] == arr2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				parent[i][j] = {i - 1, j - 1};
			}
			else{
				if(dp[i - 1][j] > dp[i][j - 1]) parent[i][j] = {i - 1, j};
				else parent[i][j] = {i, j - 1};
				
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[n][m] << "\n";
	
	vector<int> ans;
	
	int i = n;
	int j = m;
	
	while(i != 0 && j != 0){
		int a, b;
		tie(a, b) = parent[i][j];
		if(a == i - 1 && b == j - 1){
			ans.push_back(arr1[i - 1]);
		}
		
		i = a;
		j = b;
	}
	
	reverse(ans.begin(), ans.end());
	
	for(auto &x : ans){
		cout << x << ' ';
	}
	
	return 0;
}
