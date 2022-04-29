#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(int n)
{
  int answer = n - 1;
  vector<int> arr(n + 1, 0);
  for (int i = 2; i <= n; i++)
  {
    arr[i] = i;
  }
  for (int i = 2; i <= sqrt(n); i++)
  {
    for (int j = i + i; j <= n; j += i)
    {
      arr[j] = 0;
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (arr[i] == 0)
    {
      //cout << arr[i] << " ";
      answer--;
    }
  }
  return answer;
}
int main(void)
{
  int n = 5;
  cout << solution(n);
  return 0;
}