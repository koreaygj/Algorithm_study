#include <iostream>

using namespace std;

int main(void)
{
  int a;
  int b;
  int c = 0;
  int d = 0;
  cin >> a >> b;
  while (1)
  {
    cout << "*";
    c++;
    if (c == a)
    {
      cout << "\n";
      c = 0;
      d++;
    }
    if (d == b)
      break;
  }
  return 0;
}