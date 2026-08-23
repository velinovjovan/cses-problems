#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];	
	}
	
	vector<long long> segment (n * 2);
	
	segment[n] = a[0];
	for(int i = n + 1 ; i < 2 * n ; ++i){
		segment[i] = a[i - n] - a[i - n - 1];
	}
	
	for(int i = n - 1 ; i > 0 ; --i){
		segment[i] = segment[i * 2] + segment[i * 2 + 1];
	}
	
	while(q--){
		int c;
		cin >> c;
		
		if(c == 1){
			int a, b;
			long long u;
			cin >> a >> b >> u;
			--a;
			--b;
			
			a += n;
			b += n;
			
			segment[a] += u;
			for (int i = a / 2; i > 0; i /= 2) {
				segment[i] = segment[i * 2] + segment[i * 2 + 1];
			}
			
			if (b + 1 < 2 * n) {
				segment[b + 1] -= u;
				for (int i = (b + 1) / 2; i > 0; i /= 2) {
					segment[i] = segment[i * 2] + segment[i * 2 + 1];
				}
			}
			
		} 
		else{
			int k;
			cin >> k;
			--k;
			
			long long ans = 0;
			int a = n;
			int b = k + n;
			

			while (a <= b) {
				if (a % 2 == 1) ans += segment[a++];
				if (b % 2 == 0) ans += segment[b--];
				a /= 2;
				b /= 2;
			}
			
			cout << ans << "\n";
		}
	}
	
	return 0;
}
