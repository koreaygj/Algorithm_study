#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0) break;
    bool check = a > b ? true : false;
    printf("%s\n", check ? "Yes" : "No");
  }
}