#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        vector<int> powers;
        for(int i = 2 ; i * i <= a ; ++i){
        	int count = 0;
			
			while(a % i == 0){
        		a /= i;	
        		count ++;
			}
			
			if(count > 0) powers.push_back(count);
		}
		if(a > 1){
			powers.push_back(1);
		}
		
		long long ans = 1;
		
		for(auto &num : powers){
			ans *= (num + 1);
		}
		
		cout << ans << "\n";
    }

    return 0;
}
