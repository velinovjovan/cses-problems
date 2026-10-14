#include <bits/stdc++.h>

using namespace std;

struct Point{
    long long x, y;
};

long long crossProduct(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point a, Point b, Point c){
    return c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) && c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y);
}

int sign(long long val){
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

bool doIntersect(Point p1, Point p2, Point p3, Point p4){
    long long cp1 = crossProduct(p1, p2, p3);
    long long cp2 = crossProduct(p1, p2, p4);
    long long cp3 = crossProduct(p3, p4, p1);
    long long cp4 = crossProduct(p3, p4, p2);

    if (sign(cp1) != sign(cp2) && sign(cp3) != sign(cp4)){
        return true;
    }

    if (cp1 == 0 && onSegment(p1, p2, p3)) return true;
    if (cp2 == 0 && onSegment(p1, p2, p4)) return true;
    if (cp3 == 0 && onSegment(p3, p4, p1)) return true;
    if (cp4 == 0 && onSegment(p3, p4, p2)) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--){
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        
        
        if (doIntersect(p1, p2, p3, p4)){
            cout << "YES" << "\n";
        }
		else{
            cout << "NO" << "\n";
        }
    }
    
    
    return 0;
}
