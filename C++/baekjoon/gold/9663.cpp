#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> flag;
int n;
int ans = 0;
bool check(int x)
{
  for (int i = 0; i < x; i++)
  {
    if (flag[i] == flag[x] || abs(flag[x] - flag[i]) == x - i)
      return false;
  }
  return true;
}
void solution(int count)
{
  if (count == n)
  {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    flag[count] = i;
    if (check(count) == false)
      continue;
    solution(count + 1);
  }
}
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  vector<int> input(n, 0);
  flag = input;
  solution(0);
  cout << ans;
  return 0;
}