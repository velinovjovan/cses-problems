#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	stack<pair<int,int>> stek;
	stek.push({0, 0});
	
	for(int i = 0 ; i < n ; ++i){
		while(stek.top().first >= a[i]){
			stek.pop();
		}
		
		cout << stek.top().second << ' ';
		
		stek.push({a[i], i + 1});
	}
	
	
	cout << "\n";
	
	return 0;
}
