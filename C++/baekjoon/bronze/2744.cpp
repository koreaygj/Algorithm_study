#include <iostream>
using namespace std;
int main() {
  string st;
  cin >> st;
  string ans = "";
  for (int i = 0; i < st.length(); i++) {
    if (st[i] >= 'a' && st[i] <= 'z') {
      ans += (char)(st[i] - 'a' + 'A');
    } else {
      ans += (char)(st[i] - 'A' + 'a');
    }
  }
  cout << ans << "\n";
}