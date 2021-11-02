#include <iostream>
using namespace std;
int solution(int n)
{
  int answer = 0;
  for (int j = n + 1; j <= n * 2; j--)
  {
    bool flag = true;
    for (int k = 2; k * k <= j; k++)
    {
      if (j % k == 0)
      {
        flag = false;
        break;
      }
    }
    if (flag == true)
    {
      answer++;
    }
  }
  return answer;
}
int main(void)
{
  int a;
  while (1)
  {
    cin >> a;
    if (a == 0)
      break;
    else
      cout << solution(a) << "\n";
  }
  return 0;
}