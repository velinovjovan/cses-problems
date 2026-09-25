#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix power(Matrix a, long long b) {
    Matrix res = {{1, 0}, {0, 1}};
    
    while (b > 0) {
        if (b & 1) {
            res = multiply(res, a);
        }
        
        b >>= 1;
        a = multiply(a, a);
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
	cin >> n;
    
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    Matrix T = {{1, 1}, {1, 0}};
    
    Matrix ans = power(T, n);
    
    cout << ans[0][1] << "\n";

    return 0;
}
