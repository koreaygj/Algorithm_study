#include <algorithm>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int calTime(int time, int t) {
  int tmp_time = (time % 100) + t;
  time = (time / 100 + tmp_time / 60) * 100 + (tmp_time % 60);
  return time;
}

int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t, na, nb;
    cin >> t >> na >> nb;
    vector<pair<pair<int, int>, int>> times;
    for (int j = 0; j < na; j++) {
      string st, end;
      cin >> st >> end;
      int i_st = stoi(st.substr(0, 2)) * 100 + stoi(st.substr(3));
      int i_end = stoi(end.substr(0, 2)) * 100 + stoi(end.substr(3));
      times.push_back(make_pair(make_pair(i_st, i_end), 1));
    }
    for (int j = 0; j < nb; j++) {
      string st, end;
      cin >> st >> end;
      int i_st = stoi(st.substr(0, 2)) * 100 + stoi(st.substr(3));
      int i_end = stoi(end.substr(0, 2)) * 100 + stoi(end.substr(3));
      times.push_back(make_pair(make_pair(i_st, i_end), 2));
    }
    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<>> a_train_pq;
    priority_queue<int, vector<int>, greater<>> b_train_pq;
    int cnt_a = 0, cnt_b = 0;
    for (int j = 0; j < na + nb; j++) {
      int departure_time = times[j].first.first;
      int arrival_time = times[j].first.second;
      int type = times[j].second;
      if (type == 1) {
        if (!a_train_pq.empty() && a_train_pq.top() <= departure_time) {
          a_train_pq.pop();
        } else {
          cnt_a++;
        }
        b_train_pq.push(calTime(arrival_time, t));
      } else {
        if (!b_train_pq.empty() && b_train_pq.top() <= departure_time) {
          b_train_pq.pop();
        } else {
          cnt_b++;
        }
        a_train_pq.push(calTime(arrival_time, t));
      }
    }
    cout << "Case #" << i << ": " << cnt_a << " " << cnt_b << "\n";
  }
}