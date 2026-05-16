#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	long long x;
	cin >> n >> x;
	
	unordered_set<long long> a;
	unordered_map<long long, int> b;
	
	a.reserve(n * 0.7);
	b.reserve(n * 0.7);
	
	long long temp;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;
		
		if(a.count(x - temp)){
			cout << b[x - temp] << ' ' <<  i + 1;
			return 0;
		}
		
		a.insert(temp);
		b[temp] = i + 1;
	}
	
	
	cout << "IMPOSSIBLE";
	
	
	return 0;

}
