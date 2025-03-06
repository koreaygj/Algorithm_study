#include <iostream>
#include <queue>
using namespace std;
int buttonA(int number) { return number + 1 > 99999 ? -1 : number + 1; }
int buttonB(int number) {
  number *= 2;
  int temp = number;
  if (temp > 99999) return -1;
  int digitCount = 0;
  while (temp > 0) {
    temp /= 10;
    digitCount++;
  }
  int highestPlaceValue = pow(10, digitCount - 1);
  return number - highestPlaceValue;
}
int bfs(int n, int t, int g) {
  queue<pair<int, int> > q;
  q.push(make_pair(n, 0));
  bool visited[100000] = {false};
  while (!q.empty()) {
    pair<int, int> st_num = q.front();
    q.pop();
    if (st_num.first == g) {
      if (st_num.second > t) return -1;
      return st_num.second;
    }
    int result_a = buttonA(st_num.first);
    if (result_a != -1 && !visited[result_a]) {
      visited[result_a] = true;
      q.push(make_pair(result_a, st_num.second + 1));
    }
    int result_b = buttonB(st_num.first);
    if (result_b != -1 && !visited[result_b]) {
      visited[result_b] = true;
      q.push(make_pair(result_b, st_num.second + 1));
    }
  }
  return -1;
}
int main() {
  int n, t, g;
  cin >> n >> t >> g;
  int ans = 0;
  if (n == g) {
    cout << ans << "\n";
    return 0;
  }
  ans = bfs(n, t, g);
  if (ans > 0)
    cout << ans << "\n";
  else
    cout << "ANG\n";
}