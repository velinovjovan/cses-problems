#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> prices (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> prices[i];
	}
	
	int size = 1;
	while(size < n) size <<= 1;
	
	vector<int> segmentLeft (size * 2, numeric_limits<int>::max());
	vector<int> segmentRight (size * 2, numeric_limits<int>::max());
	
	for(int i = 0 ; i < n ; ++i){
		segmentLeft[i + size] = prices[i] - i;
		segmentRight[i + size] = prices[i] + i;
	}
	
	for(int i = size - 1 ; i > 0 ; --i){
		segmentLeft[i] = min(segmentLeft[i * 2], segmentLeft[i * 2 + 1]);
		segmentRight[i] = min(segmentRight[i * 2], segmentRight[i * 2 + 1]);
	}
	
	while(q--){
		int c;
		cin >> c;
		
		if(c == 1){
			int k, x;
			cin >> k >> x;
			--k; 
			
			int pos = k + size;
			segmentLeft[pos] = x - k;
			segmentRight[pos] = x + k;
			
			for(pos /= 2 ; pos > 0 ; pos /= 2){
				segmentLeft[pos] = min(segmentLeft[pos * 2], segmentLeft[pos * 2 + 1]);
				segmentRight[pos] = min(segmentRight[pos * 2], segmentRight[pos * 2 + 1]);
			}
		}
		else{
			int k;
			cin >> k;
			--k;
			
			int a = size;
			int b = k + size;
			
			int min_left = numeric_limits<int>::max();
			
			while(a <= b){
				if(a % 2 == 1){
					min_left = min(min_left, segmentLeft[a]);
					a++;
				}
				if(b % 2 == 0){
					min_left = min(min_left, segmentLeft[b]);
					b--;
				}
				
				a /= 2;
				b /= 2;
			}
			
			a = k + size;
			b = n + size - 1;
			
			int min_right = numeric_limits<int>::max();
			
			while(a <= b){
				if(a % 2 == 1){
					min_right = min(min_right, segmentRight[a]);
					a++;
				}
				if(b == 0){
					min_right = min(min_right, segmentRight[b]);
					b--;
				}
				
				a /= 2;
				b /= 2;
			}
			
			cout << min(min_left + k, min_right - k) << "\n";
		}
	}
	
	return 0;
}
