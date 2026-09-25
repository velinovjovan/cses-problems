#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long n){
    if(n <= 2) return true;
   
    for(int i = 2 ; i * i <= n ; ++i){
		if(n % i == 0){
			return false;
		}
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
		
		while(true){
			++n;
			
			if(n <= 3) break;
			if(n % 6 == 1 || n % 6 == 5){
				if(isPrime(n)) break;
			}
		}
		
		cout << n << "\n";
	}
	
	return 0;
}
