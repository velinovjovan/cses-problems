#include<bits/stdc++.h>

using namespace std;

int START = 0;
int END = 1;

struct Event {
	int pos;
	int type;
	int id;
	int p;
	
	bool operator <(const Event& b) const {
		return make_pair(pos, type) < make_pair(b.pos, b.type);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<Event> events;
	
	for(int i = 0 ; i < n ; ++i){
		int L, R, p;
		cin >> L >> R >> p;
		
		events.push_back(Event{L, START, i, p});
		events.push_back(Event{R, END, i, p});
	}
	
	sort(events.begin(), events.end());
	long long ans = 0;
	
	vector<long long> at_end(n);
	
	for(const Event& event : events){
		int type = event.type;
		int i = event.id;
		
		if(type == START){
			at_end[i] = ans + event.p;
		}
		else{
			ans = max(ans, at_end[i]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
