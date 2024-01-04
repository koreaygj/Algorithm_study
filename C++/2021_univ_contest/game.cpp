#include <iostream>
#include <vector>
using namespace std;
bool check(int a, int b)
{
  if (a - b == 1 || a - b == -2)
    return true;
  return false;
}
int main()
{
  int n;
  cin >> n;
  int A, B;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++)
  {
    cin >> A >> B;
    a.push_back(A);
    b.push_back(B);
  }
  for (int i = 0; i < n; i++)
  {
    if (check(a[i], b[i]))
      cout << "#" << i + 1 << " A\n";
    else
      cout << "#" << i + 1 << " B\n";
  }
}
