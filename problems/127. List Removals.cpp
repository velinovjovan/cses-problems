#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sz = 1;
    while(sz < n) sz <<= 1;

    vector<int> a(n);
    vector<int> segment(sz * 2, 0);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        segment[sz + i] = 1;
    }

    for(int i = sz - 1; i > 0; --i){
        segment[i] = segment[i * 2] + segment[i * 2 + 1];
    }

    while(n--){
        int br;
        cin >> br;

        int j = 1;

        while(j < sz){
            if(br <= segment[j * 2]){
                j = j * 2;
            }
            else{
                br -= segment[j * 2];
                j = j * 2 + 1;
            }
        }

        cout << a[j - sz] << " ";

        segment[j] = 0;

        for(j /= 2; j > 0; j /= 2){
            segment[j] = segment[j * 2] + segment[j * 2 + 1];
        }
    }

    return 0;
}
