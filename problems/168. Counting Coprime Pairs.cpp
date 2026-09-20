#include<bits/stdc++.h>

using namespace std;

const int maks = 1e6 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> values(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> values[i];
    }
    
    vector<vector<int>> divisors(maks);
    
    for(int i = 2 ; i < maks ; ++i){
        if(divisors[i].size() == 0){
            for(int j = i ; j < maks ; j += i){ 
                divisors[j].push_back(i);
            }
        }
    }
    
    vector<int> valuesDivisible(maks);
    vector<int> primeDivisors(maks);
    
    for(int i = 0 ; i < n ; ++i){
        for(int mask = 1 ; mask < (1 << (divisors[values[i]].size())) ; ++mask){
            int comb = 1;
            int primeDiv = 0;
            
            for(int pos = 0 ; pos < divisors[values[i]].size() ; ++pos){
                if((1 << pos) & mask){
                    primeDiv++;
                    comb *= divisors[values[i]][pos];
                }
            }
            
            valuesDivisible[comb]++;
            primeDivisors[comb] = primeDiv;
        }
    }
    
    long long total = ((long long)n * (long long)(n - 1)) / 2;
    long long valid = 0; 
    
    for(int i = 0 ; i < maks ; ++i){
        if(valuesDivisible[i] < 2) continue;
        
        long long pairsWithComb = ((long long)valuesDivisible[i] * ((long long)valuesDivisible[i] - 1) / 2);
        
        if(primeDivisors[i] & 1){
            valid += pairsWithComb;
        }
        else{
            valid -= pairsWithComb;
        }
    }
    
    cout << total - valid << "\n";
    
    return 0;
}
