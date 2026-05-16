#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	long long k = 0;
	for(int i = 0 ; i < n ; ++i){
		
		if(a[i] > k + 1){
			cout << k + 1;
			return 0;
		}
		
		k+= a[i];
	}
	
	cout << k + 1;
	
	
	return 0;
}
