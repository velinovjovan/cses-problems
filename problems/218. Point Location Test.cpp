#include<bits/stdc++.h>

using namespace std;

struct Point{
	long long x, y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){
		Point p1, p2, p3;
		
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
		
		Point vec1, vec2;
		
		vec1.x = p3.x - p1.x;
		vec1.y = p3.y - p1.y;
		
		vec2.x = p2.x - p3.x;
		vec2.y = p2.y - p3.y;
		
		long long result = vec1.x * vec2.y - vec1.y * vec2.x;
		
		if(result == 0){
			cout << "TOUCH" << "\n";
		}
		else if(result > 0){
			cout << "RIGHT" << "\n";
		}
		else{
			cout << "LEFT" << "\n";
		}
	}
	
	
	return 0;
}
