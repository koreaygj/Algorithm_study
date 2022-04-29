#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool can(double times, vector<string> plans)
{
  double fri[2] = {9.5, 18};
  double mon[2] = {13, 18};
  if (fri[1] > stod(plans[1]))
    times -= fri[1] - stod(plans[1]);
  if (mon[0] < stod(plans[2]))
    times -= stod(plans[2]) - mon[0];
  if (times >= 0)
    return 1;
  else
    return 0;
}
vector<string> time_change(vector<string> plans)
{
  string s;
  for (int j = 0; j < 2; j++)
  {
    if (plans[j + 1].size() == 3)
    {
      if (plans[j + 1][1] == 'P')
      {
        s = plans[j + 1][0];
        plans[j + 1] = to_string(stod(s) + 12);
      }
      else
        plans[j + 1] = plans[j + 1][0];
    }
    else
    {
      if (plans[j + 1][2] == 'P')
      {
        s = plans[j + 1][0];
        s += plans[j + 1][1];
        plans[j + 1] = to_string(stod(s) + 12);
      }
      else
      {
        plans[j + 1] = plans[j + 1][0];
        plans[j + 1] += plans[j + 1][1];
      }
    }
  }
  return plans;
}
string solution(double time, vector<vector<string>> plans)
{
  string ans;
  for (int i = 0; i < plans.size(); i++)
  {
    plans[i] = time_change(plans[i]);
  }
  for (int i = 0; i < plans.size(); i++)
  {
    if (can(time, plans[i]) == 1)
    {
      ans = plans[i][0];
    }
  }
  return ans;
}
int main(void)
{
  double times = 3.5;
  vector<vector<string>> plans = {{"È«Äá", "11PM", "9AM"}, {"¿¤¿¡ÀÌ", "3PM", "2PM"}};
  string ans = solution(times, plans);
  cout << ans;
  return 0;
}