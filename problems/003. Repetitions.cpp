#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
    cin >> s;
    
    int maks = 0;
    int curr = 1;
    
    for (int i = 1 ; i < int(s.length()) ; ++i)
    {
        if (s[i] != s[i - 1]){
            maks = max(maks, curr);
            curr = 0;
        }
        curr++;
    }
    
    maks = max(maks, curr);
    cout << maks;
    
    
    return 0;
   
}
