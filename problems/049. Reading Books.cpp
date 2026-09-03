#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<long long> books (n);
	
	long long sum = 0;
	long long maks = numeric_limits<long long>::min();
	for(int i = 0 ; i < n ; ++i){
		cin >> books[i];
		maks = max(maks, books[i]);
		sum += books[i];
	}
	
	cout << max(2 * maks, sum) << "\n";
	
	return 0;
}
