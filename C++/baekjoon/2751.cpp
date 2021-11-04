#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> input)
{
  sort(input.begin(), input.end());
  return input;
}
int main(void)
{
  vector<int> input;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    input.push_back(a);
  }
  vector<int> ans = solution(input);
  for (int ans : ans)
    cout << ans << "\n";
}