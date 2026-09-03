#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> a (n);
	
	for(int i = 0; i < n ; ++i){
		cin >> a[i];
	}

	int i = 0;
	int j = 0;
	int currsum = 0;
	int ans = 0;
	
	while(j < n){
		currsum += a[j];
		
		if(currsum == x){
			ans ++;
			currsum -= a[i];
			++i;
		}
		else if(currsum > x){
			while(currsum > x){
				currsum -= a[i];
				++i;
			}
			
			if(currsum == x){
				ans ++;
				currsum -= a[i];
				++i;
			}
		}
		
		++j;
	}
	
	
	cout << ans << "\n";
	
	return 0;
}

