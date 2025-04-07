#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int n;
  cin >> n;
  pair<long long, long long> lecture[n];
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a >> lecture[i].first >> lecture[i].second;
  }
  sort(lecture, lecture + n);
  int ans = 1;
  priority_queue<int, vector<int>, greater<int>> timetable;
  for (int i = 0; i < n; i++) {
    int st_time = lecture[i].first;
    int end_time = lecture[i].second;
    if (timetable.empty()) {
      timetable.push(end_time);
    } else {
      if (timetable.top() > st_time) {
        ans++;
      } else {
        timetable.pop();
      }
      timetable.push(end_time);
    }
  }
  cout << ans << "\n";
}