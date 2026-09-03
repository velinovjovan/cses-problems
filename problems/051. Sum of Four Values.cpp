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
		
		a[i] = {temp, i + 1};
	}
	
	sort(a.begin(), a.end());
	
	for(int q = 0 ; q < n ; ++q){
		for(int k = q + 1 ; k < n ; ++k){
			int i = k + 1;
			int j = n - 1;
			
			while(i < j){
				if(a[q].first + a[k].first + a[i].first + a[j].first > x){
					--j;
				}
				else if(a[q].first + a[k].first + a[i].first + a[j].first < x){
					++i;
				}
				else{
					cout << a[q].second << ' ' << a[k].second << ' ' << a[i].second << ' ' << a[j].second << "\n";
					return 0;
				}
			}
		}
	}
	
	
	cout << "IMPOSSIBLE" << "\n";
	
	return 0;
}
