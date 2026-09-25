#include<bits/stdc++.h>

using namespace std;

const int MAXN = 10000000;	
int pair_a[MAXN + 1];

void precompute() {
    memset(pair_a, -1, sizeof(pair_a));
    
    for (int i = 0; i * i <= MAXN; i++) {
        for (int j = i; i * i + j * j <= MAXN; j++) {
            int sum = i * i + j * j;
            pair_a[sum] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    
    while(t--){
    	int n;
	    cin >> n;
		
		bool flag = false;
	    for (int a = sqrt(n); a >= 0; a--) {
	        int rem1 = n - a * a;
	        
	        for (int b = sqrt(rem1); b >= 0; b--) {
	            int rem2 = rem1 - b * b;
	            
	            if (pair_a[rem2] != -1) {
	                int c = pair_a[rem2];
	                int d = sqrt(rem2 - c * c);
	                
	                cout << a << ' ' << b << ' ' << c << ' ' << d << "\n";
	                flag = true;
	                break;
	            }
	        }
	        if(flag) break;
	    }
	}

    return 0;
}
