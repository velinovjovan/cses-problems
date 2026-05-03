#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int total = 0;
    for (int i = 5 ; n / i >= 1 ; i *= 5) total += n / i;
    
    cout << total;
    
    
    return 0;

}
