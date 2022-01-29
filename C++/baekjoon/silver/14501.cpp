#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class cons
{
public:
  int t;
  int p;
};
vector<cons> week;
vector<int> pos;
int n;
int dfs(int nowday, int money)
{
  if (nowday < n)
  {
    if (week[nowday].t + nowday <= n)
      dfs(week[nowday].t + nowday, money + week[nowday].p);
    dfs(1 + nowday, money);
  }
  else
  {
    if (nowday < n)
      dfs(1 + nowday, money);
    else
      pos.push_back(money);
  }
  return 0;
}
int main(void)
{
  int t, p;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t >> p;
    week.push_back({t, p});
  }
  for (int i = 0; i < n; i++)
  {
    dfs(i, 0);
  }
  cout << endl;
  cout << *max_element(pos.begin(), pos.end());
  return 0;
}