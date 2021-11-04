#include <iostream>
using namespace std;
int solution(int n)
{
  int answer = 666;
  while (n != 1)
  {
    bool flag = false;
    int b;
    answer++;
    b = answer;
    while (b >= 666)
    {
      if (b % 1000 == 666)
      {
        flag = true;
        break;
      }
      b /= 10;
    }
    if (flag == true)
      n--;
  }
  return answer;
}
int main(void)
{
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}