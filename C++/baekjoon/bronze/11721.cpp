#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length() / 10 + 1; i++) {
    if (i == s.length() / 10)
      cout << s.substr(i * 10) << "\n";
    else
      cout << s.substr(i * 10, 10) << "\n";
  }
}