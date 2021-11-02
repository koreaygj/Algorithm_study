#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
  int a, b, c = 0;
  cin >> a >> b;
  cin.ignore();
  for (int i = 0; i < 3; i++)
  {
    cout << a * (b % 10) << endl;
    c += a * (b % 10) * pow(10, i);
    b /= 10;
  }
  cout << c << endl;
  return 0;
}