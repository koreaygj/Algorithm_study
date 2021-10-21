#include <iostream>
#include <vector>
using namespace std;
int solution(int n)
{
  vector<int> num(3, 0);
  int answer = 0;
  int k, count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i == 1000)
      break;
    if (i < 100)
      answer++;
    else
    {
      k = i;
      count = 0;
      while (k != 0)
      {
        num[count] = k % 10;
        k /= 10;
        count++;
      }
      if (num[1] * 2 == num[0] + num[2])
      {
        cout << i << endl;
        answer++;
      }
    }
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