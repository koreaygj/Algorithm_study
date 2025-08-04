#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int N;
set<string> Visited;

bool check_win(string cards) {
  int a = 0, b = 0;
  for (int i = 0; i < cards.length(); i += 2) {
    if (cards[i] > cards[i + 1])
      a++;
    else if (cards[i] < cards[i + 1])
      b++;
  }
  return a > b;
}

string cheat(string cards, int index) {
  return cards[index] + cards.substr(0, index) + cards.substr(index + 1);
}

int bfs(string cards) {
  queue<pair<string, int>> q;
  q.push(make_pair(cards, 0));
  Visited.insert(cards);
  int ans = 0;

  while (!q.empty()) {
    string cur = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (check_win(cur)) {
      ans = cnt;
      break;
    }

    for (int i = 1; i < cards.length(); i++) {
      string next = cheat(cur, i);

      if (Visited.find(next) == Visited.end()) q.push(make_pair(next, cnt + 1));
    }
  }
  return ans;
}

int main() {
  fastio;
  cin >> N;
  string cards = "";
  for (int i = 0; i < N * 2; i++) {
    char tmp;
    cin >> tmp;
    if (tmp == 'O')
      cards += '1';
    else
      cards += '0';
  }

  cout << bfs(cards) << "\n";

  return 0;
}