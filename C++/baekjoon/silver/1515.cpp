#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int main() {
  fastio;
  string num;
  cin >> num;
  int index = 0;
  int cur = 1;

  while (index != num.length()) {
    string num_str = to_string(cur);

    for (int i = 0; i < num_str.length(); i++) {
      if (num[index] == num_str[i]) {
        index++;
        if (index >= num.length()) {
          cout << cur << "\n";
          exit(0);
        }
      }
    }
    cur++;
  }

  return 0;
}