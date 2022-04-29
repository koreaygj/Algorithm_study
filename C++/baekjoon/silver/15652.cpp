#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
int n, m;
vector<int> input;
vector<int> ans;
void print()
{
  for (int i = 0; i < m; i++)
    cout << ans[i] << " ";
  cout << "\n";
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
    if (count != 0 && input[i] < ans.back())
      continue;
    ans.push_back(input[i]);
    solution(count + 1);
    ans.pop_back();
  }
}
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    input.push_back(i);
  solution(0);
  return 0;
}
