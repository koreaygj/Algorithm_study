#include <iostream>
#include <vector>
using namespace std;
int solution(int x, int y, vector<string> board)
{
  int answer;
  int size = (x + 1) * y;
  vector<int> count;
  vector<string> ans, err1, err2;
  for (int i = 0; i < size; i++)
  {
    int n = i / y;
    if (i % 2 == 0)
      ans[n] += "B";
    else
      ans[n] += "W";
  }
  err1 = ans;
  err1.erase(err1.begin());
  err2 = ans;
  err2.pop_back();
  for (int i = 0; i < size / x; i++)
  {
    int a = i / y;
    int b = i % x;
    if (err1[a][b] != board[a][b])
      err1[a][b] = 1;
    if (err2[a][b] != board[a][b])
      err2[a][b] = 1;
  }
  for(int i = 0; i < 
  int ncount = 0, ncount2 = 0;
  for (int i = 0; i < 64; i++)
  {
    int a = i / 8;
    int b = i % 8;
    if (err1[a][b] == 1)
      ncount++;
    if (err2[a][b] == 1)
      ncount2++;
  }
  return answer;
}
int main(void)
{
  int x, y;
  vector<string> board;
  cin >> x >> y;
  for (int i = 0; i < x; i++)
  {
    string s;
    cin >> s;
    board.push_back(s);
  }
  cout << solution(x, y, board);
  return 0;
}