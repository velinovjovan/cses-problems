#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long n){
    if (n < 2) return false;
    if (n == 2) return true;
    if(n % 2 == 0) return false;
    
    for (long long x = 3 ; x * x <= n ; x += 2){
        if (n % x == 0) return false;
    }
    
    return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		
		++n;
		while(!isPrime(n)) ++n;
		
		cout << n << "\n";
	}
	
	return 0;
}
