#include<bits/stdc++.h>

using namespace std;

vector<int> veza;
vector<int> size;

int find(int a){
	while(veza[a] != a) a = veza[a];
	return a;
}

bool same(int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	
	if(size[b] > size[a]) swap(a, b);
	size[a] += size[b];
	veza[b] = a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	veza.resize(n + 1);
	size.resize(n + 1);
	
	for(int i = 1 ; i <= n ; ++i) veza[i] = i;
	for(int i = 1 ; i <= n ; ++i) size[i] = 1;
	
	int brComp = n;
	int maksSize = 1;
	
	for(int i = 0 ; i < m ; ++i){
		int a, b;
		cin >> a >> b;
		
		if(same(a, b)){
			cout << brComp << ' ' << maksSize << "\n";
		}
		else{
			unite(a, b);
			brComp --;
			maksSize = max(maksSize, size[find(a)]);
			
			cout << brComp << ' ' << maksSize << "\n";
		}
	}
	
	return 0;
}
