#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int state[MAXN];
int p[MAXN];

int cycle_start = -1;
int cycle_end = -1;

bool dfs(int node) {
	state[node] = 1;
	
	for (auto &x : adj[node]) {
		if (state[x] == 0) {
			p[x] = node;
			if (dfs(x)) return true;
		} 
		else if (state[x] == 1) {
			cycle_end = node;
			cycle_start = x;
			return true;
		}
	}
	
	state[node] = 2;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0 ; i < m ; ++i) {
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
	}
	
	for (int i = 1 ; i <= n ; ++i) {
		if (state[i] == 0) {
			if (dfs(i)) break;
		}
	}
	
	if (cycle_start == -1) {
		cout << "IMPOSSIBLE" << "\n";
	} 
	else {
		vector<int> ans;
		ans.push_back(cycle_start);
		
		for (int v = cycle_end ; v != cycle_start ; v = p[v]) {
			ans.push_back(v);
		}
		ans.push_back(cycle_start);
		
		reverse(ans.begin(), ans.end());
		
		cout << ans.size() << "\n";
		for (auto &x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
