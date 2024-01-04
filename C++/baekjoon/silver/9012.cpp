#include <iostream>
#include <vector>
using namespace std;
bool solution(string s)
{
  vector<int> vps;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      vps.push_back(1);
    }
    if (s[i] == ')')
    {
      if (vps.empty())
        return 0;
      if (vps.back() == 1)
      {
        vps.pop_back();
      }
      else
        vps.push_back(0);
    }
  }
  if (vps.empty())
    return 1;
  else
    return 0;
}
int main(void)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    if (solution(s))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}