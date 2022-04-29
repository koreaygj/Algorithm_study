#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num, answer;
vector<int> oper, order;
int n;
int max, min;
void cal()
{
  int ans = num[0];
  for (int i = 0; i < n - 1; i++)
  {
    switch (order[i])
    {
    case 0:
      ans += num[i + 1];
      break;
    case 1:
      ans -= num[i + 1];
      break;
    case 2:
      ans *= num[i + 1];
      break;
    case 3:
      ans /= num[i + 1];
      break;
    }
  }
  answer.push_back(ans);
}
void solution(int count)
{
  if (count == n - 1)
  {
    cal();
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (oper[i] == 0)
      continue;
    order[count] = i;
    oper[i] -= 1;
    solution(count + 1);
    oper[i] += 1;
  }
}
int main(void)
{
  // ios_base::sync_with_stdio(false);
  // cout.tie(NULL);
  // cin.tie(NULL);
  int k;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    num.push_back(a);
    order.push_back(0);
  }
  for (int i = 0; i < 4; i++)
  {
    int b;
    cin >> b;
    oper.push_back(b);
  }
  solution(0);
  cout << *max_element(answer.begin(), answer.end()) << "\n";
  cout << *min_element(answer.begin(), answer.end()) << "\n";
  return 0;
}