#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long a = 0;
  for (int i = 0; i < 3; i++) {
    long long b = 0;
    cin >> b;
    a += b;
  }
  cout << a << "\n";
}