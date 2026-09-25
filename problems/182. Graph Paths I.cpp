#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &A, const Matrix &B){
	Matrix C (A.size(), vector<long long> (A.size()));
	
	for(int i = 0 ; i < (int)A.size() ; ++i){
		for(int k = 0 ; k < (int)A.size() ; ++k){
			for(int j = 0 ; j < (int)A.size() ; ++j){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
			}
		}
	}
	
	return C;
}

Matrix power(Matrix a, long long b){
	Matrix ans (a.size(), vector<long long> (a.size()));
	for(int i = 0 ; i < (int)a.size() ; ++i){
		ans[i][i] = 1;
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
	
	Matrix matrica (n, vector<long long> (n, 0));
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		--a;
		--b;
			
		matrica[a][b] ++;
	}
	
	matrica = power(matrica, k);
	
		
	cout << matrica[0][n - 1];
	
	return 0;
}
