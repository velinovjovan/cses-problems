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
	
	map<int, long long> mapa;
	
	for(int i = 0 ; i < k ; ++i){
		mapa[val[i]] ++;
	}
	
	for(int i = k ; i < n ; ++i){
		cout << mapa.size() << ' ';
		
		mapa[val[i - k]] --;
		if(mapa[val[i - k]] == 0){
			mapa.erase(val[i - k]);
		}
		
		mapa[val[i]] ++;
	}
	cout << mapa.size() << "\n";
	
	
	return 0;
}
