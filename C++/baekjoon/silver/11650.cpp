#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class dot
{
public:
  int x;
  int y;
};
bool comp(dot a, dot b)
{
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}
int main(void)
{
  int n;
  cin >> n;
  vector<dot> num;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    num.push_back({a, b});
  }
  sort(num.begin(), num.end(), comp);
  for (int i = 0; i < n; i++)
  {
    cout << num[i].x << " " << num[i].y << "\n";
  }
  return 0;
}