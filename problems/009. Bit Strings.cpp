#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long n;
	long long r = 2;
    cin >> n;
    
    for(int i = 1 ; i < n ; ++i){
    	r *= 2;
    	r %= MOD;
	}
    
    cout << r;
    
    
    return 0;
    
}
