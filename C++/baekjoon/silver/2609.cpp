#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
 int a, b;
 int gcf = 1, lcm = 1;
 cin >> a >> b;
 if (a > b)
  swap(a, b);
 while (1)
 {
  bool flag = false;
  for (int i = 2; i <= a; i++)
  {
   if (a % i == 0 && b % i == 0)
   {
    flag = true;
    a /= i;
    b /= i;
    gcf *= i;
    break;
   }
  }
  if (flag == false)
   break;
 }
 lcm = gcf * a * b;
 cout << gcf << "\n";
 cout << lcm << "\n";
 return 0;
}