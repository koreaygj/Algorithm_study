#include <iostream>
#include <vector>
using namespace std;
int main() {
  string n;
  cin >> n;
  vector<char> stick;
  int ans = 0;
  for (int i = 0; i < n.length(); i++) {
    if (n[i] == '(') {
      if (i + 1 < n.length() && n[i + 1] == ')') {
        ans += stick.size();
        i++;
      } else {
        stick.push_back('(');
      }
    } else {
      stick.pop_back();
      ans++;
    }
  }
  ans += stick.size();
  cout << ans << "\n";
}