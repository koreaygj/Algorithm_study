#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> solution(vector<int> n)
{
  int answer = 0;
  vector<int> result;
  bool flag;
  for (int i = 0; i < n.size(); i++)
  {
    answer = 0;
    for (int j = n[i] * 2; j > n[i]; j--)
    {
      flag = true;
      for (int k = 2; k <= sqrt(j); k++)
      {
        if (j % k == 0)
        {
          flag = false;
          break;
        }
        else
          flag = true;
      }
      if (flag == true)
      {
        answer++;
      }
    }
    result.push_back(answer);
  }
  return result;
}
int main(void)
{
  vector<int> n;
  vector<int> ans;
  int a;
  while (a != 0)
  {
    cin >> a;
    cin.ignore();
    n.push_back(a);
  }
  ans = solution(n);
  for (int ans : ans)
  {
    if (ans != 0)
      cout << ans << "\n";
  }
  return 0;
}
