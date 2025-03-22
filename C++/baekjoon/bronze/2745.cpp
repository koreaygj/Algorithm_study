#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  string n;
  int b;
  cin >> n >> b;
  long long int ans = 0;
  for (size_t i = 0; i < n.length(); i++) {
    if (n[i] >= 'A') {
      ans += (n[i] - 'A' + 10) * pow(b, n.length() - 1 - i);
    } else {
      ans += (n[i] - '0') * pow(b, n.length() - 1 - i);
    }
  }
  cout << ans << "\n";
}