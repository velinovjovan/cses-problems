#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> val (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> val[i];
	}
	
	map<long long, int> mapa;
	set<pair<int, long long>> set;
	
	for(int i = 0 ; i < k ; ++i){
		mapa[val[i]] ++;
	}
	
	for(auto x : mapa){
		set.insert({x.second, -x.first});
	}
	
	for(int i = k ; i < n ; ++i){
		cout << - ((--set.end())->second) << ' ';
		
		set.erase({mapa[val[i - k]], -val[i - k]});
		mapa[val[i - k]] --;
		set.insert({mapa[val[i - k]], -val[i - k]});
		
		
		set.erase({mapa[val[i]], -val[i]});
		mapa[val[i]] ++;
		set.insert({mapa[val[i]], -val[i]});
	}
	cout << - ((--set.end())->second) << "\n";
	
	
	return 0;
}
