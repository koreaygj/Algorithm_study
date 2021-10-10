#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(int num)
{
  int answer = 0;
  long d = num;
  while (1)
  {
    answer++;
    if (d == 1)
      break;
    if (d % 2 == 0)
      d = d / 2;
    else
      d = (d * 3 + 1);
    if (d == 1)
    {
      break;
    }
    if (answer >= 500 && d != 1)
    {
      answer = -1;
      break;
    }
  }
  return answer;
}
int main(void)
{
  int a = 6;
  cout << solution(a);
  return 0;
}