#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	multiset<long long> a;
	vector<long long> b (m);
	
	long long temp;
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;
		a.insert(temp);
	}
	
	for(int i = 0 ; i < m ; ++i){
		cin >> b[i];
		
		auto it = a.upper_bound(b[i]);
		if(it == a.begin()){
			cout << -1 << '\n';
		}
		else{
			--it;
			cout << *it << '\n';
			a.erase(it);
		}
	}
	
	
	
	return 0;

}
