#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int a, b;
 while (1)
 {
  cin >> a >> b;
  if (a == 0 && b == 0)
   break;
  if (a <= b && b % a == 0)
   cout << "factor\n";
  else if (a >= b && a % b == 0)
   cout << "multiple\n";
  else
   cout << "neither\n";
 }
 return 0;
}