#include<bits/stdc++.h>

using namespace std;

struct Point{
    long long x, y;
};

long long crossProduct(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point a, Point b, Point c){
    return crossProduct(a, b, c) == 0 && c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) && c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> points(n);

    for(int i = 0 ; i < n ; ++i){
        cin >> points[i].x >> points[i].y;
    }

    for(int j = 0 ; j < m ; ++j){
        Point curr;
        cin >> curr.x >> curr.y;

        int ans = 0;
        bool boundary = false;

        for(int i = 0 ; i < n ; ++i){
            Point a = points[i];
            Point b = points[(i + 1) % n];

            if(onSegment(a, b, curr)){
                boundary = true;
                break;
            }

            if((a.y > curr.y) != (b.y > curr.y)){
                long long cp = crossProduct(a, b, curr);

                if((b.y > a.y && cp > 0) || (b.y < a.y && cp < 0)){
                    ans++;
                }
            }
        }

        if(boundary) cout << "BOUNDARY\n";
        else if(ans & 1) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
        
    }

    return 0;
}
