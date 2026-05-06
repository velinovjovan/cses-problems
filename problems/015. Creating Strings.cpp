#include<bits/stdc++.h>

using namespace std;
const long long  mod = 1e9 + 7;

set<string> perms;

void permutations(string prefix, string suffix){
   
    if (suffix.length() == 0){
        perms.insert(prefix);
        return;
    }
    
    for (int i = 0; i < suffix.length(); ++i) permutations(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
    cin >> s;
    permutations("", s);
    
    cout << perms.size() << endl;
    
    for (auto ele : perms) cout << ele << endl;
    
    
    return 0;

}
