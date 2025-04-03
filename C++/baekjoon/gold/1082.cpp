#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first > b.first;
  return a.second < b.second;
}
void solution(vector<pair<int, int>> num, vector<pair<int, int>> s_num, int n,
              int m) {
  vector<int> room;
  if (n == 1) {
    int tmp = m / s_num[0].second;
    for (int i = 0; i < tmp; i++) cout << s_num[0].first;
    cout << "\n";
    return;
  }
  if (s_num[0].first == 0) {
    if (s_num[1].second > m) {
      cout << "0\n";
      return;
    } else {
      room.push_back(s_num[1].first);
      m -= s_num[1].second;
    }
  }
  for (int i = 0; i < s_num.size(); i++) {
    if (s_num[i].second <= m) {
      int tmp = m / s_num[i].second;
      m %= s_num[i].second;
      for (int j = 0; j < tmp; j++) room.push_back(s_num[i].first);
    }
  }
  sort(room.begin(), room.end(), greater<>());
  for (int i = 0; i < room.size(); i++) {
    for (int j = n - 1; j > 0; j--) {
      if (room[i] < num[j].first && num[j].second - num[room[i]].second <= m) {
        m -= num[j].second - num[room[i]].second;
        room[i] = num[j].first;
        break;
      }
    }
  }
  for (const auto digit : room) cout << digit;
  cout << "\n";
  return;
}

int main() {
  fastio;
  int n;
  cin >> n;
  vector<pair<int, int>> num;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    num.push_back(make_pair(i, p));
  }
  vector<pair<int, int>> s_num = num;
  sort(s_num.begin(), s_num.end(), comp);
  int m;
  cin >> m;
  solution(num, s_num, n, m);
}