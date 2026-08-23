#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sz = 1;
    while(sz < n) sz <<= 1;

    vector<int> segment(sz * 2);

    for(int i = 0; i < n; ++i){
        cin >> segment[sz + i];
    }

    for(int i = sz - 1; i > 0; --i){
        segment[i] = max(segment[i * 2], segment[i * 2 + 1]);
    }

    while(m--){
        int r;
        cin >> r;

        if(segment[1] < r){
            cout << 0 << " ";
        }
        else{
            int j = 1;

            while(j < sz){
                if(segment[j * 2] >= r)
                    j *= 2;
                else
                    j = j * 2 + 1;
            }

            cout << j - sz + 1 << " ";

            segment[j] -= r;

            j /= 2;

            while(j > 0){
                segment[j] = max(segment[j * 2], segment[j * 2 + 1]);
                j /= 2;
            }
        }
    }

    return 0;
}
