#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<long long> a (n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	
	int fast = 0;
	int slow = 0;
	unordered_set<long long> unique;
	unique.reserve(n * 0.7);
	int curr = 0;
	int maks = 0;
	
	while(fast < n){
		if(unique.count(a[fast])){
			unique.erase(a[slow]);
			++slow;
			--curr;
		}
		else{
			unique.insert(a[fast]);
			++fast;
			++curr;
		}
		
		maks = max(curr, maks);
	}
	
	cout << maks;
	
	
	return 0;
	
}
