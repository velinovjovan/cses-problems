#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	long long temp;
	long long ans = 0, curr = 0;
	
	for(int i = 0 ; i < n ; i++){
		
		cin >> temp;
		
		if(temp >= curr) curr = temp;
		else ans += curr - temp; 	
	}
	
	cout << ans;
	
	
	return 0;
}
