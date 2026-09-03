#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}

	long long prefix_sum = 0;
	long long ans = 0;
	map<long long, int> sums;
	
	sums[0] = 1;
	
	for (auto &val : a) {
		prefix_sum += val;
		ans += sums[prefix_sum - x];
		sums[prefix_sum]++;
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
