#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x;
	cin >> n >> x;
	
	vector<pair<int,int>> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		int temp;
		cin >> temp;
		
		a[i] = {temp, i};
	}
	
	sort(a.begin(), a.end());
	
	for(int q = 0 ; q < n ; ++q){

		int i = q + 1;
		int j = n - 1;
		
		while(i < j){
			if(a[q].first + a[i].first + a[j].first > x){
				--j;
			}
			else if(a[q].first + a[i].first + a[j].first < x){
				++i;
			}	
			else{
				cout << a[q].second + 1 << ' ' << a[i].second + 1 << ' ' << a[j].second + 1 << "\n";
				return 0;
			}
		}
	}
	
	cout << "IMPOSSIBLE" << "\n";
	
	return 0;
}
