#include<bits/stdc++.h>

using namespace std;

vector<int> z(string s){
	int n = s.size();
	vector<int> z (n);
	int x = 0;
	int y = 0;
	
	for(int i = 1 ; i < n ; ++i){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
			x = i;
			y = i + z[i];
			z[i] ++;
		}
	}
	
	return z;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	string p;
	cin >> p;
	
	string res = p + "#" + s;
	
	vector<int> vektor = z(res);
	
	int ans = 0;
	for(int i = (int)p.length() + 1 ; i < (int)p.length() + (int)s.length() + 1 ; ++i){
		if(vektor[i] == (int)p.length()) ans ++;
	}
	
	cout << ans << "\n";
	
	return 0;
}
