#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
  int n, count, num = 0;
  long int size = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    size += pow(10, a);
  }
  while (size != 0)
  {
    num += 1;
    count = size % 10;
    for (int i = 0; i < count; i++)
      cout << num << "\n";
    size /= 10;
  }
  return 0;
}