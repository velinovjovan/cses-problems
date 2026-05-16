#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long n;
	cin >> n;
	
	long long temp;
	unordered_set<long long> a;
	a.reserve(n * 0.7);
	int ans = 0;
	
	for(long long i = 0 ; i < n ; ++i){
		cin >> temp;
		if(!a.count(temp)){
			ans++;
			a.insert(temp);
		}
	}
	
	cout << ans;
	
	
	return 0;
	
}
