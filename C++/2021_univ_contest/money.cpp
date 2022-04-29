#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans, can;
string s;
void dfs(int index, int current)
{
  if (current == can)
  {
    ans = max(ans, stoi(s));
    return;
  }
  for (int i = index; i < s.size() - 1; i++)
  {
    for (int j = i + 1; j < s.size(); j++)
    {
      swap(s[i], s[j]);
      dfs(i, current + 1);
      swap(s[i], s[j]);
    }
  }
}

int main(void)
{
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    cin >> s >> can;
    ans = 0;
    if (can > s.size())
      can = s.size();
    dfs(0, 0);
    cout << "#" << i << " " << ans << endl;
  }
  return 0;
}