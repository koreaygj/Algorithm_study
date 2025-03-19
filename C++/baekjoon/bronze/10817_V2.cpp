#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int result =
      a ^ b ^ c ^ std::min(std::min(a, b), c) ^ std::max(std::max(a, b), c);
  cout << result << "\n";
  return 0;
}
