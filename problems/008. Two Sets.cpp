#include<iostream>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n%4 == 1 || n%4 == 2) cout << "NO";
    else if(n%4 == 3)
	{
        cout << "YES\n";
        cout << n/2 << '\n';
        
        for(int i = 2; i <= n/2; i += 2)
    		cout << i << ' ' <<  n-i << ' ';
            
        cout << n << '\n' << n/2 + 1 << '\n';
        
        for(int i = 1; i <= n/2; i += 2)
            cout << i << ' ' <<  n-i << ' ';
            
    } 
	else 
	{
        cout << "YES\n";
        cout << n/2 << '\n';
        
        for(int i = 2; i <= n/2; i += 2)
    		cout << i << ' ' <<  n-i+1 << ' ';
    		
        cout << '\n' << n/2 << '\n';
        
        for(int i = 1; i <= n/2; i += 2)
            cout << i << ' ' <<  n-i+1 << ' ';
    }
    
    
    return 0;
}
