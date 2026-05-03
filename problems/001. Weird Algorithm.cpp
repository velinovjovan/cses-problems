#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unsigned long long n;
	cin >> n;
	
	while(n != 1){
		cout << n << ' ';
		if(n&1) n = n * 3 + 1;
		else n = n / 2;
	}
	
	cout << 1 << ' ';
	
	
	return 0;
}
