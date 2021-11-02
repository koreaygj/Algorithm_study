#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  vector<int> answer(10000, 0);
  vector<int> result;
  int num = 0;
  int size = 0;
  for (int i = 1; i < 10000; i++)
  {
    num = i;
    size = i;
    while (num >= 10)
    {
      size += num % 10;
      num /= 10;
    }
    size += num;
    answer[size]++;
  }
  for (int i = 1; i < 10000; i++)
  {
    if (answer[i] == 0)
    {
      cout << i << "\n";
    }
  }
  return 0;
}