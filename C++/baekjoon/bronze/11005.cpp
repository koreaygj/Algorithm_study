#include <iostream>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  string ans = "";
  while (n > 0) {
    int tmp = n % b;
    n /= b;
    if (tmp < 10)
      ans = (char)('0' + tmp) + ans;
    else
      ans = (char)('A' + tmp - 10) + ans;
  }
  cout << ans << "\n";
}