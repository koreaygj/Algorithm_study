#include <iostream>
using namespace std;
long long solution(int price, int money, int count)
{
  int answer = 0;
  for (int i = 1; i <= count; i++)
  {
    answer += price * i;
  }
  answer = money - answer < 0 ? answer - money : 0;
  return answer;
}
int main(void)
{
  int price = 3;
  int money = 20;
  int count = 4;
  cout << solution(price, money, count);
  return 0;
}