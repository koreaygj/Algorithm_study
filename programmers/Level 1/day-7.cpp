#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int solution(int left, int right)
{
  int answer = 0;
  int mid = 0;
  for (int i = left; i <= right; i++)
  {
    mid = sqrt(i);
    if (i == pow(mid, 2))
      answer -= i;
    else
      answer += i;
  }
  return answer;
}
int main(void)
{
  int a = 13;
  int b = 17;
  solution(a, b);
  return 0;
}