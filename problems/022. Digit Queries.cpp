#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long k;
	cin >> k;
	
	long long count = 9;
	long long skipped = 0;
	int len = 1;
	
	while(k > len * count){
		k -= len * count;
		skipped += count;
		++len;
		count*= 10;
	}
	
	long long skip = (k - 1) /len;
	skipped += skip;
	k -= skip * len;
	
	long long x = skipped + 1;
	cout << to_string(x)[k - 1] << '\n';
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
}
