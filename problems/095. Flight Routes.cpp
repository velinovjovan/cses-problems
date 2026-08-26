#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<int,int>>> adj (n + 1);
		
	for (int i = 0 ; i < m ; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({b, c});
	}
	
	vector<priority_queue<long long>> best (n + 1);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	
	best[1].push(0);
	pq.push({0, 1});
	
	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();
		
		if (node.first > best[node.second].top()) continue;
		
		for (auto &x : adj[node.second]) {
			long long temp = node.first + x.second;
			
			if (best[x.first].size() < k){
				best[x.first].push(temp);
				pq.push({temp, x.first});
			} 
			else if (temp < best[x.first].top()) {
				best[x.first].pop();
				best[x.first].push(temp);
				pq.push({temp, x.first});
			}
		}
	}
	
	vector<long long> ans;
	while (!best[n].empty()) {
		ans.push_back(best[n].top());
		best[n].pop();
	}
	
	reverse(ans.begin(), ans.end());
	for (auto &x : ans){
		cout << x << ' ';
	}
	
	
	return 0;
}
