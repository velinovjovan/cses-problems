#include<bits/stdc++.h>

using namespace std;

struct Range{
	int x;
	int y;
	int id;
	
	bool operator<(const Range &a){
		if(x == a.x) return y > a.y;
		return x < a.x;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<Range> ranges (n);
	
	for(int i = 0 ; i < n ; ++i){
		int a, b;
		cin >> a >> b;
		
		ranges[i] = {a, b, i};
	}
	
	sort(ranges.begin(), ranges.end());
	
	
	vector<int> contains (n);
	vector<int> contained (n);
	
	int currMax = 0;
	for(int i = 0 ; i < n ; ++i){
		if(ranges[i].y <= currMax) contained[ranges[i].id] = 1;
		currMax = max(currMax, ranges[i].y);
	}
	
	int currMin = numeric_limits<int>::max();
	for(int i = n - 1 ; i >= 0 ; --i){
		if(ranges[i].y >= currMin) contains[ranges[i].id] = 1;
		currMin = min(currMin, ranges[i].y);
	}
	
	for(auto &x : contains){
		cout << x << ' ';
	}
	
	cout << "\n";
	
	for(auto &x : contained){
		cout << x << ' ';
	}
	
	cout <<  "\n";
	
	
	return 0;
}
