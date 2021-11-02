#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> solution(int m, int n)
{
  int answer;
  vector<int> num;
  bool flag;
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
  return num;
}
int main(void)
{
  int m, n = 0;
  cin >> m >> n;
  vector<int> answer = solution(m, n);
  for (int answer : answer)
    cout << answer << "\n";
  return 0;
}