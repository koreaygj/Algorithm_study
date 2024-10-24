#include <iostream>
#include <math.h>
using namespace std;
int N, M, H;
bool Visited[11];
int Milk[11][2];
int Ans = 0;
int MilkCnt;
int HomeX, HomeY;
int calLength(int stY, int stX, int endY, int endX)
{
  return abs(endY - stY) + abs(endX - stX);
}

void backTrace(int stY, int stX, int energy, int cnt)
{
  for (int i = 0; i < MilkCnt; i++)
  {
    if (Visited[i])
      continue;
    int length = calLength(stY, stX, Milk[i][0], Milk[i][1]);
    if (length > energy)
      continue;
    Visited[i] = true;
    energy -= length;
    backTrace(Milk[i][0], Milk[i][1], energy + H, cnt + 1);
    Visited[i] = false;
    energy += length;
  }
  int lengthToHome = calLength(stY, stX, HomeY, HomeX);
  if (lengthToHome <= energy)
    Ans = cnt > Ans ? cnt : Ans;
  return;
}

int main()
{
  cin >> N >> M >> H;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int tmp;
      cin >> tmp;
      if (tmp == 1)
      {
        HomeY = i;
        HomeX = j;
      }
      else if (tmp == 2)
      {
        Milk[MilkCnt][0] = i;
        Milk[MilkCnt][1] = j;
        MilkCnt++;
      }
    }
  }
  backTrace(HomeY, HomeX, M, 0);
  cout << Ans << "\n";
  return 0;
}