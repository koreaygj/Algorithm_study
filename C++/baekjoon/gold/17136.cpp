#include <iostream>
using namespace std;
bool checkNxN(int **board, int y, int x, int n)
{
  if (y + n > 10 || x + n > 10)
    return false;
  for (int i = y; i < y + n; i++)
  {
    for (int j = x; j < x + n; j++)
    {
      if (!board[i][j])
        return false;
    }
  }
  return true;
}

void updateBoard(int **board, int y, int x, int n, int value)
{
  for (int i = y; i < y + n; i++)
  {
    for (int j = x; j < x + n; j++)
    {
      board[i][j] = value;
    }
  }
}

int backtrack(int **board, int *paperCnt, int y, int x)
{
  if (x == 10)
    return backtrack(board, paperCnt, y + 1, 0);
  if (y == 10)
    return 0;
  if (board[y][x] == 0)
    return backtrack(board, paperCnt, y, x + 1);

  int minPaper = 26;

  for (int size = 5; size > 0; size--)
  {
    if (paperCnt[size] > 0 && checkNxN(board, y, x, size))
    {
      updateBoard(board, y, x, size, 0);
      paperCnt[size]--;

      int result = backtrack(board, paperCnt, y, x + 1);
      if (result != -1)
        minPaper = min(minPaper, result + 1);

      updateBoard(board, y, x, size, 1);
      paperCnt[size]++;
    }
  }
  return (minPaper == 26) ? -1 : minPaper;
}

int main()
{
  int **board = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    board[i] = new int[10];
  }
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cin >> board[i][j];
    }
  }
  int paperCnt[6] = {0, 5, 5, 5, 5, 5};
  int ans = 0;
  ans = backtrack(board, paperCnt, 0, 0);
  cout << ans << "\n";
  for (int i = 0; i < 10; i++)
  {
    delete[] board[i];
  }
  delete[] board;
  return 0;
}