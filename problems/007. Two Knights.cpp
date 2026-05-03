#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long k;
    cin >> k;
    
    for(long n = 1; n <= k; ++n) cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << "\n";
	
	
	return 0;
}
