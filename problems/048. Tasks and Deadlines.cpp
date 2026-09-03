#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<pair<int,int>> tasks (n);
	
	for(int i = 0 ; i < n ; ++i){
		int a, b;
		cin >> a >> b;
		
		tasks[i] = {a, b};
	}
	
	sort(tasks.begin(), tasks.end());
	
	long long ans = 0;
	long long time = 0;
	for(int i = 0 ; i < n ; ++i){
		time += tasks[i].first;
		ans += tasks[i].second - time;
	}	
	
	cout << ans << "\n";
	
	return 0;
}
