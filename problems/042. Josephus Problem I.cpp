#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    
    while (!q.empty()) {
        int killer = q.front();
        q.pop();
        q.push(killer);
        
        cout << q.front() << ' ';
        
        q.pop();
    }
    
    cout << "\n";
    
    return 0;
}
