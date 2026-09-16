#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> val (n);
	vector<long long> sorted (n);
		
	for(int i = 0 ; i < n ; ++i){
		cin >> val[i];
		sorted[i] = val[i];
	}
	
	sort(sorted.begin(), sorted.end());

	map<long long, int> mapa;
	map<int, long long> invmapa;
	
	int br = 1;
	for(auto &x : sorted){
		mapa[x] = br;
		invmapa[br] = x;
		br++;
	}
	
	int size = 1;
	while(size < n ) size <<= 1;
	
	vector<long long> segment (size * 2);
	
	long long ans = 0;
	
	for(int i = 0 ; i < n ; ++i){
		long long add = size + mapa[val[i]] - 1;
		
		int a = add + 1;
		int b = size + n - 1;
		
		while(a <= b){
			if(a % 2 == 1) ans += segment[a++];
			if(b % 2 == 0) ans += segment[b--];
			
			a /= 2;
			b /= 2;
		}
		
		segment[add] ++;
		for(add /= 2 ; add > 0 ; add /= 2){
			segment[add] = segment[add * 2] + segment[add * 2 + 1];
		}
		
		if(i >= k){
			int remove = size + mapa[val[i - k]] - 1;
			
			int a = size;
			int b = remove - 1;
			
			while(a <= b){
				if(a % 2 == 1) ans -= segment[a ++];
				if(b % 2 == 0) ans -= segment[b --];
				
				a /= 2;
				b /= 2;
			}
			
			segment[remove] --;
			for(remove /= 2 ; remove > 0 ; remove /= 2){
				segment[remove] = segment[remove * 2] + segment[remove * 2 + 1];
			}
		}
		
		if(i >= k - 1){
			cout << ans << ' ';
		}
	}
	
	cout << "\n";
	
	
	return 0;
	
}
