#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  bool switches[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> switches[i];
  }
  int st;
  cin >> st;

  for (int i = 0; i < st; i++) {
    int gen, num;
    cin >> gen >> num;
    if (gen == 1) {
      for (int j = num; j <= n; j += num) switches[j] = !switches[j];
    } else {
      switches[num] = !switches[num];
      int cnt = 1;
      while (0 < num - cnt && num + cnt <= n) {
        if (switches[num - cnt] == switches[num + cnt]) {
          switches[num - cnt] = !switches[num - cnt];
          switches[num + cnt] = !switches[num + cnt];
        } else {
          break;
        }
        cnt++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << switches[i] << " ";
    if (i % 20 == 0) cout << "\n";
  }
  return 0;
}