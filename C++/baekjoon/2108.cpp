#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> solution(vector<int> num)
{
  vector<int> ans;
  vector<int> index(8002, 0);
  int count = 0, mode = 0, size = num.size();
  double sum = 0;
  sort(num.begin(), num.end());
  for (int i = 0; i < size; i++)
  {
    index[num[i] + 4000]++;
    sum += num[i];
  }
  for (int i = 0; i <= 8000; i++)
  {
    if (index[i] == *max_element(index.begin(), index.end()))
    {
      count++;
      mode = i - 4000;

      if (count == 2)
        break;
    }
  }
  ans.push_back(round(sum / size));
  ans.push_back(num[size / 2]);
  ans.push_back(mode);
  ans.push_back(num.back() - num.front());
  return ans;
}
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, a;
  vector<int> num;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    num.push_back(a);
  }
  vector<int> ans = solution(num);
  for (int ans : ans)
  {
    cout << ans << "\n";
  }
  return 0;
