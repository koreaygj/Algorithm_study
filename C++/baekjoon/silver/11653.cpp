#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> solution(int a)
{
  vector<int> answer;
  int i = 2;
  while (a != 1)
  {
    if (a % i == 0)
    {
      answer.push_back(i);
      a /= i;
      i = 2;
    }
    else
      i++;
  }
  return answer;
}
int main(void)
{
  int a;
  cin >> a;
  vector<int> ans;
  ans = solution(a);
  for (int ans : ans)
    cout << ans << "\n";
  return 0;
}