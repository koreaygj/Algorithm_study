#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
  int m, n;
  cin >> m >> n;
  bool flag = false;
  vector<int> num;
  vector<int> result;
  int answer = 0;
  for (int i = m; i <= n; i++)
  {
    flag = false;
    for (int j = 2; j <= sqrt(i); j++)
    {
      if (i % j == 0)
      {
        flag = false;
        break;
      }
      else
        flag = true;
    }
    if (flag == true || i == 2 || i == 3)
    {
      num.push_back(i);
      answer += i;
    }
  }
  if (answer == 0)
  {
    cout << -1;
  }
  else
  {
    result.push_back(answer);
    result.push_back(num.front());
    for (int i = 0; i < result.size(); i++)
      cout << result[i] << "\n";
  }
  return 0;
}