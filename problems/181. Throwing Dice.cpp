#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& A, const Matrix& B){
	Matrix C (6, vector<long long> (6, 0));
	
	for(int i = 0 ; i < 6 ; ++i){
		for(int k = 0 ; k < 6 ; ++k){
			for(int j = 0 ; j < 6 ; ++j){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
			}
		}
	}
	
	return C;
}

Matrix power(Matrix a, long long b){
	Matrix res = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
	
	while(b){
		if(b & 1){
			res = multiply(res, a);
		}
		b >>= 1;
		a = multiply(a, a);
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n;
	cin >> n;
	
	vector<long long> prva = {1,1,2,4,8,16};
	
	if(n <= 5){
		cout << prva[n] << "\n";
		return 0;
	}
	
	n -= 5;
	
	Matrix T = {{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{1,1,1,1,1,1}};
	T = power(T, n);
	
	vector<long long> ans = {0,0,0,0,0,0};
	
	for(int i = 0 ; i < 6 ; ++i){
		for(int j = 0 ; j < 6 ; ++j){
			ans[i] = (ans[i] + T[i][j] * prva[j]) % mod;
		}
	}
	
	cout << ans[5] << "\n";
	
	
	return 0;
}
