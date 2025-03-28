#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_wi
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int ans = 1;
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < b; j++) {
      ans = a * (ans % 10);
    }
    printf("%d\n", ans % 10 == 0 ? 10 : ans % 10);
  }
}