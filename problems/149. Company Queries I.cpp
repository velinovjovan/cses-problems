#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> parent (n + 1);
	
	for(int i = 2 ; i <= n ; ++i){
		int a;
		cin >> a;
		
		parent[i] = a;
	}
	
	int temp = n;
	int size = 0;
	while(temp){
		size ++;
		temp >>= 1;
	}
	
	vector<vector<int>> sparse (size, vector<int> (n + 1));
	
	for(int i = 0 ; i < size ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(i == 0){
				sparse[i][j] = parent[j];
			}
			else{
				sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
			}
		}
	}
	
	while(q--){
		int x, k;
		cin >> x >> k;
		
		int node = x;
		int i = 0;
		while(k){
			if(k&1){
				node = sparse[i][node];
			}
			k >>= 1;
			++i;
		}
		if(node == 0) node = -1;
		cout << node << "\n";
	}
	
	return 0;
}
