#include<bits/stdc++.h>

using namespace std;

struct Movie {
    int start;
    int end;
    
    bool operator < (const Movie &a) const {
    	if(end == a.end) return start < a.start;
    	return end < a.end;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end());
    multiset<int> times;
    
    for (int i = 0; i < k; ++i) {
        times.insert(0);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        auto it = times.upper_bound(movies[i].start);
        
        if (it != times.begin()) {
            --it;
        
            times.erase(it);
            times.insert(movies[i].end);
        	ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
