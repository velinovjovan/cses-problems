#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int divisors[MAX + 1];

void precompute() {
    for (int i = 1; i <= MAX; ++i) {
        for (int j = i; j <= MAX; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        cout << divisors[a] << "\n";
    }

    return 0;
}
