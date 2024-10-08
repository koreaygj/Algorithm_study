#include <iostream>
using namespace std;
// https://codeforces.com/problemset/problem/282/A

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    string s = "";
    cin >> s;
    if (s[1] == '+')
      ans++;
    else
      ans--;
  }
  cout << ans << "\n";
  return 0;
}
