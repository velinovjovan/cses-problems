#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int t;
    cin >> t;
    
    long long x, y;

    while (t--){
        cin >> x >> y;
        
        if (x < y){
        	
            if (y % 2){
                long r = y * y;
                cout << r - x + 1 << "\n";
            }
            else {
                long r = (y - 1) * (y - 1) + 1;
                cout << r + x - 1 << "\n";
            }
        }
        else {
        	
            if (x % 2){
            	long r = (x - 1) * (x - 1) + 1;
                cout << r + y - 1 << "\n";
            }
            else {
                long r = x * x;
                cout << r - y + 1 << "\n";
            }
        }
    }
    
    
    return 0;
}
