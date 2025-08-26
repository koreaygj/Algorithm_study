#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main() {
  fastio;

  int n;
  cin >> n;
  int cnt = 0;
  bool check[1000001];
  fill(&check[0], &check[0] + 1000001, 0);

  while (n--) {
    int x, y, z;
    cin >> x >> y >> z;

    if (!(check[x] || check[y] || check[z])) cnt++;

    check[x] = check[y] = check[z] = 1;
  }

  cout << cnt;
  return 0;
}