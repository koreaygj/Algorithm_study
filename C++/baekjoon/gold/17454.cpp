#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main() {
  fastio;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (c >= d || e >= f || e * c > (f - e) * (d - c)) {
      cout << "GOD\n";
    } else {
      cout << "KDH\n";
    }
  }
}