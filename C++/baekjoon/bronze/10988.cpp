#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  const char *st = s.c_str();
  const char *end = s.c_str() + s.length() - 1;
  while (st <= end) {
    if (*st != *end) {
      cout << "0\n";
      return 0;
    }
    st++;
    end--;
  }
  cout << "1\n";
  return 0;
}