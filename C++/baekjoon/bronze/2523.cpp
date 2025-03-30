#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string star = "*";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) cout << star;
    cout << "\n";
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 1; j <= i; j++) cout << star;
    cout << "\n";
  }
}