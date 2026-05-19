#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<long long> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	multiset<long long> baze;
	
	for(int i = 0 ; i < n ; ++i){
		auto it = baze.upper_bound(a[i]);
		if(it != baze.end()){
			baze.erase(it);
		}
		
		baze.insert(a[i]);
	}
	
	cout << baze.size();
	
	
	return 0;
}
