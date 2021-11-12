#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> input;
vector<int> ans;
int n, m;
void print()
{
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return;
}
void solution(int count)
{
  if (count == m)
  {
    print();
    return;
  }
  for (int i = 0; i < n; i++)
  {
    ans.push_back(input[i]);
    solution(count + 1);
    ans.pop_back();
  }
}
int main(void)
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    input.push_back(i);
  }
  solution(0);
  return 0;
}