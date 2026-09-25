#include<bits/stdc++.h>

using namespace std;
vector<long long> nums;
const long long maks = 1e12 + 1;

void precompute() {
    for (long long i = 1; ; i++) {
        long long val = i * (i + 1) / 2;
        nums.push_back(val);
        if (val > maks) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    
	while(t--) {
		long long n;
	    cin >> n;
	
	    if (binary_search(nums.begin(), nums.end(), n)) {
	        cout << 1 << "\n";
	        continue;
	    }
		
		bool flag = false;
	
	    int i = 0;
	    int j = upper_bound(nums.begin(), nums.end(), n) - nums.begin() - 1;
	    
	    while (i <= j) {
	        long long sum = nums[i] + nums[j];
	        
	        if (sum == n){
	            cout << 2 << "\n";
	            flag = true;
	            break;
	        } 
			else if (sum < n) i++;
	        else j--;
	    }
	    
	    if(flag) continue;
	
	    cout << 3 << "\n";
	}

    return 0;
}
