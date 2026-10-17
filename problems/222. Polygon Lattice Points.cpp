#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
};

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ans += polygon[i - 1].x * polygon[i].y;
            ans -= polygon[i - 1].y * polygon[i].x;
        }
    }
    
    ans += polygon[n - 1].x * polygon[0].y;
    ans -= polygon[n - 1].y * polygon[0].x;
    
    if (ans < 0) ans = -ans;
    
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i == n - 1 ? 0 : i + 1);
        
        long long g = gcd(abs(polygon[i].x - polygon[j].x), abs(polygon[i].y - polygon[j].y));
        answer += g;
    }
    
    cout << (ans - answer + 2) / 2 << ' ' << answer << "\n";
    
    return 0;
}
