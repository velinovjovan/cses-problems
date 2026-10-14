#include<bits/stdc++.h>

using namespace std;

struct Point{
	long long x, y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<Point> points (n);
	
	long long ans = 0;
	for(int i = 0 ; i < n ; ++i){
		cin >> points[i].x >> points[i].y;
		
		if(i > 0){
			ans += points[i - 1].x * points[i].y;
			ans -= points[i - 1].y * points[i].x;
		}
	}
	
	ans += points[n - 1].x * points[0].y;
	ans -= points[n - 1].y * points[0].x;
	
	if(ans < 0) ans = -ans;
	
	
	cout << ans << "\n";
	
	
	return 0;
}
