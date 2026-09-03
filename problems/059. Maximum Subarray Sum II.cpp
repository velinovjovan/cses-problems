#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> arr(n + 1);
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }

    multiset<long long> ms;
    long long max_sum = numeric_limits<long long>::min();

    for (int i = a; i <= n; i++) {
        ms.insert(pref[i - a]);

        if (i > b) {
            ms.erase(ms.find(pref[i - b - 1]));
        }

        max_sum = max(max_sum, pref[i] - *ms.begin());
    }

    cout << max_sum << "\n";

    return 0;
}
