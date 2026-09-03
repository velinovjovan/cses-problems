#include<bits/stdc++.h>

using namespace std;

vector<int> veza;
vector<int> size;

int find(int x){
	while(x != veza[x]) x = veza[x];
	return x;
}

bool same(int &a, int &b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	
	if(size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	veza[b] = a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<tuple<int,int,int>> edges;
	
	for(int i = 0 ; i < m ; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		
		edges.push_back(make_tuple(c, a, b));
	}
	
	sort(edges.begin(), edges.end());
	
	veza.resize(n + 1);
	size.resize(n + 1);
	
	for(int i = 1 ; i <= n ; ++i) veza[i] = i;
	for(int i = 1 ; i <= n ; ++i) size[i] = 1;
	
	
	long long ans = 0;
	int br = 0;
	for(auto &edge : edges){
		int a, b, c;
		tie(c, a, b) = edge;
		
		if(!same(a, b)){
			ans += c;
			br ++;
			unite(a, b);
		}
	}
	
	if(br == n - 1){
		cout << ans << "\n";
	}
	else{
		cout << "IMPOSSIBLE" << "\n";
	}
	
	return 0;
}
