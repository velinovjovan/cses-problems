#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> x (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> x[i];
	}
	
	long long ans = 0;
	
	unordered_set<int> vals;
	
	int i = 0;
	int j = 0;
	
	while(j < n){
		if(vals.count(x[j])){
			vals.erase(x[i]);
			++i;
		}
		else{
			vals.insert(x[j]);
			
			ans += j - i + 1;
			++j;
		}
	}
	
	
	cout << ans;
	
	
	return 0;
}
