#include<bits/stdc++.h>

using namespace std;

const long long A = 313;
const long long B = 1e9 + 9;

long long get_hash(int l, int r, const vector<long long>& hesh, const vector<long long>& p) {
    long long h = hesh[r];
    if (l > 0) {
        h = (h - (hesh[l - 1] * p[r - l + 1]) % B + B) % B;
    }
    return h;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	vector<long long> heshfront (n);
	vector<long long> pfront (n);
	
	heshfront[0] = (long long)s[0];
	pfront[0] = 1;
	
	for(int i = 1 ; i < n ; ++i){
		heshfront[i] = (heshfront[i - 1] * A + (long long)s[i]) % B;
		pfront[i] = (pfront[i - 1] * A) % B;
	}

	
	int left = 0;
	int right = n - 1;
	
	for(int i = 0 ; i < n - 1 ; ++i){
		long long prefix = get_hash(0, left, heshfront, pfront);
		long long suffix = get_hash(right, n - 1, heshfront, pfront);
		
		if(prefix == suffix){
			cout << left + 1 << ' ';
		}
		
		left ++;
		right --;
	}
	
	cout << "\n";
	
	
	return 0;
}
