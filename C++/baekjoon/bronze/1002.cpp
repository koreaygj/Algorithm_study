#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int solution(vector<int> n)
{
  int answer = 0;
  double length = sqrt(pow(n[0] - n[3], 2) + pow(n[1] - n[4], 2));
  if (length == 0 && n[2] == n[5])
    return -1;
  if (length < n[2] || length < n[5])
  {
    if (length < abs(n[2] - n[5]))
      answer = 0;
    else if (length == abs(n[2] - n[5]))
      answer = 1;
    else
      answer = 2;
  }
  else
  {
    if (length > n[2] + n[5])
      answer = 0;
    else if (length == n[2] + n[5])
      answer = 1;
    else
      answer = 2;
  }
  return answer;
}
int main(void)
{
  vector<int> ans;
  int n;
  int a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    vector<int> n;
    for (int j = 0; j < 6; j++)
    {
      cin >> a;
      n.push_back(a);
    }
    ans.push_back(solution(n));
  }
  for (int ans : ans)
  {
    cout << ans << "\n";
  }
  return 0;
}