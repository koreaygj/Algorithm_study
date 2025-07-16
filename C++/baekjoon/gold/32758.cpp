#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  int event[n];
  int count[n];
  for (int i = 0; i < n; i++) cin >> event[i];
  for (int i = 0; i < n; i++) cin >> count[i];

  for (int i = 0; i < n; i++) {
    int ans = 0;
    if (count[i] < event[i]) {
      ans = count[i];
    } else if (count[i] % event[i] == 0) {
      ans = count[i] - (count[i] / event[i] - 1);
    } else {
      ans = count[i] - (count[i] / event[i]);
    }

    cout << ans << " ";
  }
  cout << "\n";
  return 0;
}