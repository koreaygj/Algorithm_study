#include <iostream>
using namespace std;
double calArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return abs(a.first * (b.second - c.second) + b.first * (c.second - a.second) +
             c.first * (a.second - b.second)) /
         2.0;
}
bool isOwnedTree(pair<int, int> rect[3], int x, int y, double area) {
  double temp = calArea(rect[0], rect[1], make_pair(x, y)) +
                calArea(rect[1], rect[2], make_pair(x, y)) +
                calArea(rect[2], rect[0], make_pair(x, y));
  return temp == area;
}
int main() {
  pair<int, int> rect[3];
  for (int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    rect[i].first = a;
    rect[i].second = b;
  }
  double area = calArea(rect[0], rect[1], rect[2]);
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans = isOwnedTree(rect, x, y, area) ? ans + 1 : ans;
  }
  printf("%.1f\n", area);
  printf("%d\n", ans);
}