#include <bits/stdc++.h>

using namespace std;

void dfs(int pos, vector<vector<int>> &flights, vector<bool> &visited) {
	for (int c : flights[pos]) {
		if (visited[c]) continue;
		visited[c] = true;
		dfs(c, flights, visited);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> forward_graph(n);
	vector<vector<int>> reverse_graph(n);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		forward_graph[a].push_back(b);
		reverse_graph[b].push_back(a);
	}

	vector<bool> visited(n);
	dfs(0, forward_graph, visited);
	
	for (int i = 1; i < n; i++) {
		if (visited[i] == false) {
			cout << "NO\n";
			cout << 1 << " " << i + 1 << "\n";
			return 0;
		}
	}

	visited = vector<bool>(n, false);
	dfs(0, reverse_graph, visited);
	
	for (int i = 1; i < n; i++) {
		if (visited[i] == false) {
			cout << "NO" << endl;
			cout << i + 1 << " " << 1 << "\n";
			return 0;
		}
	}

	cout << "YES" << endl;
	
	
	return 0;
}
