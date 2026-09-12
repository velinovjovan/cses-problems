#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> parent (n + 1, 0);
	vector<int> depth (n + 1, 0);	

	for(int i = 2 ; i <= n ; ++i){
		int a;
		cin >> a;
		
		parent[i] = a;
		depth[i] = depth[a] + 1;
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
		int a, b;
		cin >> a >> b;
		
		if(depth[a] < depth[b]){
			swap(a, b);
		}
		
		int diff = depth[a] - depth[b];
		int i = 0;
		while(diff){
			if(diff & 1){
				a = sparse[i][a];
			}
			++i;
			diff >>= 1;
		}
		
		if (a == b) {
			cout << a << "\n";
			continue;
		}
		
		for (int i = size - 1 ; i >= 0 ; --i) {
			if (sparse[i][a] != sparse[i][b]) {
				a = sparse[i][a];
				b = sparse[i][b];
			}
		}

		cout << parent[a] << "\n";
	}
	
	
	return 0;
}
