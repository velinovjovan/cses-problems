#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	map<long long, char> a;
	
	long long temp;
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;
		a[temp] = 1;
		cin >> temp;
		a[temp] = -1;
	}
	
	int maks = 0;
	int curr = 0;
	
	for(auto x : a){
		if(x.second == 1) curr ++;
		else curr --;
		
		maks = max(maks, curr);
	}
	
	cout << maks;
	
	
	return 0;
	
}
