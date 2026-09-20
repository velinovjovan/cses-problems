#include <iostream>

using namespace std;

int find(int n, int k){
    if (n == 1) return 1;
    
    if (k <= (n + 1) / 2){
        if (2 * k > n) return (2 * k) % n;
        else return 2 * k;
    }
    
    if (n & 1){
        return 2 * find(n / 2, k - (n + 1) / 2) + 1;
    }
    else{
    	return 2 * find(n / 2, k - (n + 1) / 2) - 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    int q;
    cin >> q;

    while(q--){
        int n, k;
        cin >> n >> k;
        
        cout << find(n, k) << "\n";
    }

    return 0;
}


