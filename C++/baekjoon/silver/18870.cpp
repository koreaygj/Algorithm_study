#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> input;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    input.push_back(a);
  }
  vector<int> ans = input;
  sort(input.begin(), input.end());
  input.erase(unique(input.begin(), input.end()), input.end());
  for (int i = 0; i < ans.size(); i++)
  {
    cout << lower_bound(input.begin(), input.end(), ans[i]) - input.begin() << " ";
  }
  return 0;
}