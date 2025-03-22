#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string star = "*";
  for (int i = 0; i < n; i++) {
    for (int j = n - i - 2; j >= 0; j--) cout << " ";
    cout << star << "\n";
    star += "**";
  }
}