#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  int coins[4] = {25, 10, 5, 1};
  for (int i = 0; i < t; i++) {
    int c;
    int changes[4] = {0};
    cin >> c;
    for (int j = 0; j < 4; j++) {
      changes[j] = c / coins[j];
      c = c % coins[j];
      if (c % coins[j] == 0) break;
    }
    for (const auto change : changes) cout << change << " ";
    cout << "\n";
  }
}