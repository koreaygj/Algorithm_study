#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
 vector<int> n(10, 0);
 int num = 0;
 int index = -1;
 for (int i = 0; i < 10; i++)
 {
  cin >> n[i];
 }
 for (int i = 0; i < 10; i++)
 {
  if (num >= 100)
  {
   index = i;
   break;
  }
  num += n[i];
 }
 if (index == -1 && num > 100)
  index = 10;
 if (num == 100)
  cout << num;
 else if (num > 100)
 {
  if (num - 100 > abs(num - n[index - 1] - 100))
   cout << num - n[index - 1];
  else
   cout << num;
 }
 else
  cout << num;
 return 0;
}