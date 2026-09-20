#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n;
	int k;
	
	cin >> n >> k;
	
	vector<long long> primes (k);
	
	for(int i = 0 ; i < k ; ++i){
		cin >> primes[i];
	}
	
	vector<long long> contribution (k + 1);
	
	for(int mask = 1 ; mask < (1 << k) ; ++mask){
		int num = 0;
		long long temp = n;
		
		for(int i = 0 ; i < k ; ++i){
			if((1 << i) & mask){
				num ++;
				temp /= primes[i];		
			}
		}
		
		contribution[num] += temp;
	}
	
	long long ans = 0;
	
	for(int i = 1 ; i <= k ; ++i){
		if(i & 1){
			ans += contribution[i];
		}
		else{
			ans -= contribution[i];
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
