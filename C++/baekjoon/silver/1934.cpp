#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcf(int a, int b)
{
 if (b == 0)
  return a;
 return gcf(b, a % b);
}
int main(void)
{
 int n;
 cin >> n;
 int a, b;
 int answer;
 for (int i = 0; i < n; i++)
 {
  cin >> a >> b;
  if (a < b)
   swap(a, b);
  answer = gcf(a, b);
  a /= answer;
  b /= answer;
  cout << answer * a * b << "\n";
 }
 return 0;
}