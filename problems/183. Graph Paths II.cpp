#include<bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max();
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &A, const Matrix &B){
	Matrix C (A.size(), vector<long long> (A.size(), INF));
	
	for(int i = 0 ; i < (int)A.size() ; ++i){
		for(int k = 0 ; k < (int)A.size() ; ++k){
			if(A[i][k] == INF) continue;
			for(int j = 0 ; j < (int)A.size() ; ++j){
				if(B[k][j] == INF) continue;
				C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
			}
		}
	}
	
	return C;
}

Matrix power(Matrix a, long long b){
	Matrix ans (a.size(), vector<long long> (a.size(), INF));
	for(int i = 0 ; i < (int)a.size() ; ++i){
		ans[i][i] = 0; 
	}
	
	while(b){
		if(b & 1){
			ans = multiply(ans, a);
		}
		b >>= 1;
		a = multiply(a, a);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	long long k;
	cin >> n >> m >> k;
	
	Matrix matrica (n, vector<long long> (n, INF));
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
	
		--a;
		--b;
		
		matrica[a][b] = min(matrica[a][b], c);
	}
	
	matrica = power(matrica, k);
		
	if(matrica[0][n - 1] == INF) cout << -1 << "\n";
	else cout << matrica[0][n - 1] << "\n";
	
	
	return 0;
}
