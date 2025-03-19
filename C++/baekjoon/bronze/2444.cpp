#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string star[n + 1];
  for (int i = 1; i <= n; i++) {
    string tmp = "*";
    string space;
    for (int j = 0; j < n - i; j++) space += " ";
    for (int j = 1; j < i; j++) tmp += "**";
    star[i] = space + tmp;
    cout << star[i] << "\n";
  }
  for (int i = n - 1; i > 0; i--) {
    cout << star[i] << "\n";
  }
}