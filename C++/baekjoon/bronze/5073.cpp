#include <algorithm>
#include <iostream>
#include <map>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
bool isValid(int a, int b, int c) {
  if (a >= b && a >= c) return a < b + c;
  if (b >= c && b >= a) return b < a + c;
  if (c >= a && c >= b) return c < a + b;
}
int main() {
  fastio;
  int a, b, c;
  while (true) {
    map<int, int> m;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;
    m.insert({a, 1});
    m.insert({b, 1});
    m.insert({c, 1});
    if (!isValid(a, b, c)) {
      cout << "Invalid\n";
      continue;
    }
    if (m.size() == 3)
      cout << "Scalene\n";
    else if (m.size() == 2)
      cout << "Isosceles\n";
    else
      cout << "Equilateral\n";
  }
}