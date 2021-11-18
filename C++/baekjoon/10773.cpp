#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int n, sum = 0;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      ans.pop_back();
      continue;
    }
    ans.push_back(a);
  }
  for (int i = 0; i < ans.size(); i++)
  {
    sum += ans[i];
  }
  cout << sum << "\n";
  return 0;
}
