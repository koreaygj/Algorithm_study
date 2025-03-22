#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string center = "*";
  string repeat = "**";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = 0; j < n - i - 1; j++) cout << repeat;
    cout << center << "\n";
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) cout << " ";
    for (int j = 0; j < i; j++) cout << repeat;
    cout << center << "\n";
  }
}