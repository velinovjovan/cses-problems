#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	
	vector<long long> val (n);
	val[0] = x;
	
	for(int i = 1 ; i < n ; ++i){
		val[i] = (a * val[i - 1] + b) % c;
	}
	long long ans = 0;
	
	deque<int> red;

	for(int i = 0 ; i < n ; ++i) {
	    if(!red.empty() && red.front() <= i - k) {
	        red.pop_front();
	    }
	    
	    while(!red.empty() && val[red.back()] >= val[i]) {
	        red.pop_back();
	    }
	    red.push_back(i);
	    
	    if(i >= k - 1) {
			ans = ans ^ val[red.front()];
	    }
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
