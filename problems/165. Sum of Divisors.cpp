#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INV2 = 500000004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long total_sum = 0;
    long long left = 1;

    while (left <= n) {
        long long quotient = n / left;
        long long right = n / quotient;

        long long count = (right - left + 1) % MOD;
        long long endpoint = (left % MOD + right % MOD) % MOD;
        
        long long sum = (endpoint * count) % MOD;
        sum = (sum * INV2) % MOD;

        long long val = (sum * (quotient % MOD)) % MOD;
        total_sum = (total_sum + val) % MOD;

        left = right + 1;
    }

    cout << total_sum << "\n";

    return 0;
}
