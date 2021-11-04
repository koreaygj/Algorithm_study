#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
  int x = 0;
  int y = 0;
};
bool comp(point a, point b)
{
  if (a.y <= b.y)
  {
    if (a.y == b.y && a.x >= a.x)
      return false;
    else
      return true;
  }
  else
    return false;
}
int main(void)
{
  int n = 0;
  cin >> n;
  cin.ignore();
  vector<point> dot;
  int x, y = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    cin.ignore();
    dot.push_back({x, y});
  }
  sort(dot.begin(), dot.end(), comp);
  for (int i = 0; i < n; i++)
  {
    cout << dot[i].x << " " << dot[i].y << '\n';
  }
  return 0;
}