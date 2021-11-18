#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cal(int a, int b)
{
  int sum = a + b;
  if (sum >= 24)
  {
    sum %= 24;
  }
  return sum;
}
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << "#" << i + 1 << " " << cal(a, b) << endl;
  }
}
