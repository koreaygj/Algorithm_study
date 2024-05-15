#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  int board[100][100];
  int blackCnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = x - 1; i < x + 10; i++)
    {
      for (int j = y - 1; j < j + 10; j++)
      {
        if (board[i][j] != 0)
          continue;
        board[i][j] = 1;
        blackCnt++;
      }
    }
  }
  printf("%d", blackCnt);
  return 0;
}