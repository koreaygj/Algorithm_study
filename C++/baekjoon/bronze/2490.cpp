#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
int main() {
  int arr[4];
  fastio;
  while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]) {
    int cntTop = 0, cntBot = 0;
    for (const auto a : arr) {
      if (a == 0)
        cntTop++;
      else
        cntBot++;
    }
    if (cntTop == 1)
      cout << "A\n";
    else if (cntTop == 2)
      cout << "B\n";
    else if (cntTop == 3)
      cout << "C\n";
    else if (cntTop == 4)
      cout << "D\n";
    else
      cout << "E\n";
  }
}