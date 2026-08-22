#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> segment (2 * n, 0);
	
	for(int i = n ; i < 2 * n ; ++i){
		cin >> segment[i];
	}
	
	for(int i = n - 1 ; i > 0 ; --i){
		segment[i] = min(segment[i * 2], segment[i * 2 + 1]);
	}
	
	while(q--){
		int c, a, b;
		cin >> c >> a >> b;
		
		if(c == 2){
			--a;
			--b;
			
			a += n;
			b += n;
			
			int ans = numeric_limits<int>::max();
			while(a <= b){
			    if(a % 2 == 1) ans = min(ans, segment[a++]); 
			    if(b % 2 == 0) ans = min(ans, segment[b--]);
			    
			    a /= 2;
			    b /= 2;
			}
			
			cout << ans << "\n";
		}
		else{
			--a;
			a += n;
			segment[a] = b;
			for(a /= 2 ; a > 0 ; a /= 2){
				segment[a] = min(segment[a * 2], segment[2 * a + 1]);
			} 
		}
	}
}
