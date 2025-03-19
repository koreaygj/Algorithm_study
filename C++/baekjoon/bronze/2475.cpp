#include <iostream>
using namespace std;
int main() {
  int tmp;
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    cin >> tmp;
    ans += (tmp * tmp) % 10;
  }
  cout << ans % 10 << "\n";
}