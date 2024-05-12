#include <stdio.h>
int main()
{
  int roomNum = 0;
  int numCard[10] = {0};
  int packCount = 0;
  scanf("%d", &roomNum);
  while (roomNum > 0)
  {
    int num = roomNum % 10;
    roomNum /= 10;
    if (num == 6 || num == 9)
    {
      if (numCard[6] > numCard[9])
      {
        numCard[9]++;
        num = 9;
      }
      else
      {
        numCard[6]++;
        num = 6;
      }
    }
    else
    {
      numCard[num]++;
    }
    packCount < numCard[num] ? packCount = numCard[num] : packCount;
  }
  printf("%d", packCount);
  return 0;
}