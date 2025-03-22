#include <iostream>
using namespace std;
int main() {
  int alphabet[26] = {0};
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) alphabet[s[i] - 'a']++;
  for (const auto ans : alphabet) cout << ans << " ";
  cout << "\n";
}