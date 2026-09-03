#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int check(long long maxVal){
	
	long long currVal = 0;
	int ans = 1;
	
	for(auto &x : a){
		if(currVal + x > maxVal){
			ans++;
			currVal = x;
		}	
		else{
			currVal += x;
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	a.resize(n);
	
	long long max_elem = 0; 
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
		max_elem = max(max_elem, (long long)a[i]);
	}
	
	long long i = max_elem;
	long long j = 1e18;
	long long ans = numeric_limits<long long>::max();
	
	while(i <= j){
		long long middle = i + (j - i) / 2;
		
		if(check(middle) > k){
			i = middle + 1;
		}
		else{
			ans = min(ans, middle);
			j = middle - 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
