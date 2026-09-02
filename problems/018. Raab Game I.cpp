#include <bits/stdc++.h>
using namespace std;

bool test_case() {
	int n, a, b;
	cin >> n >> a >> b;
	int ties = n - a - b;
	if (ties < 0) {
		return false;
	}
	n -= ties;
	if (n < 0) {
		return false;
	}
	
	if (n >= 1 && (a == n || b == n)) {
		return false;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	for (int i = n + 1; i <= n + ties; i++) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		int x = i + a;
		if (x > n) {
			x -= n;
		}
		cout << x << " ";
	}
	for (int i = n + 1; i <= n + ties; i++) {
		cout << i << " ";
	}
	cout << "\n";
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		if (!test_case()) {
			cout << "NO\n";
		}
	}
}
