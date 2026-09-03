#include <bits/stdc++.h>

using namespace std;

const int START = 0;
const int END = 1;

struct Event {
    int x;
    int type; // START or END
    int id;  
    
    bool operator<(const Event &b) const {
        if (x != b.x) return x < b.x;
        return type < b.type;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Event> events;
    events.reserve(n * 2);
    
    for(int i = 0 ; i < n ; ++i){
        int a, b;
        cin >> a >> b;
    
        events.push_back({a, START, i});
        events.push_back({b, END, i});
    }
    
    sort(events.begin(), events.end());
    
    vector<int> ans_rooms(n); 
    vector<int> free_rooms; 
    
    int max_rooms = 0;
    
    for(auto &event : events){
        if(event.type == START){
            if(free_rooms.empty()){
                max_rooms++;
                ans_rooms[event.id] = max_rooms;
            } else {
                ans_rooms[event.id] = free_rooms.back();
                free_rooms.pop_back();
            }
        }
        else {
            free_rooms.push_back(ans_rooms[event.id]);
        }
    }
    
    cout << max_rooms << "\n";
    
    for(int i = 0; i < n; i++){
        cout << ans_rooms[i] << ' ';
    }
    cout << "\n";
    
    return 0;
}
