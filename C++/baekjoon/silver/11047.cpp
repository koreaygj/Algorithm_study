#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int n, k;
 int answer = 0;
 cin >> n >> k;
 vector<int> unit(n, 0);
 for (int i = 0; i < n; i++)
  cin >> unit[i];
 while (k != 0)
 {
  n--;
  if (k % unit[n] != k)
  {
   answer += k / unit[n];
   k = k % unit[n];
  }
 }
 cout << answer << "\n";
}