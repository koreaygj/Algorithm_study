#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string star = "";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    star += "*";
    cout << star;
    for (int j = (n - i) * 2; j > 0; j--) cout << " ";
    cout << star << "\n";
  }
  for (int i = n - 1; i > 0; i--) {
    star = star.substr(1);
    cout << star;
    for (int j = (n - i) * 2; j > 0; j--) cout << " ";
    cout << star << "\n";
  }
}