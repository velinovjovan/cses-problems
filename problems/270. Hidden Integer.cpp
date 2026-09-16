#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int j = 1e9;
	int i = 1;
	
	while(i <= j){
		if(i == j){
			cout << '!' << ' ' << i << endl;
			return 0;
		}
		else{
			int mid = i + (j - i) / 2;
			
			cout << '?' << ' ' << mid << endl;
			
			string s;
			cin >> s;
			
			if(s[0] == 'Y'){
				i = mid + 1;
			}
			else{
				j = mid;
			}
		}
	}
	
	
	return 0;
}
