#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int x, int y, vector<string> board)
{
  int answer;
  vector<int> count;
  string ans1 = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
  string ans2 = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
  for (int i = 0; i <= x - 8; i++)
  {
    for (int j = 0; j <= y - 8; j++)
    {
      int ncount = 0, ncount2 = 0;
      for (int k = 0; k < 64; k++)
      {
        int a = i + k / 8;
        int b = j + k % 8;
        if (board[a][b] == ans1[k])
        {
          ncount++;
        }
        if (board[a][b] == ans2[k])
        {
          ncount2++;
        }
      }
      count.push_back(ncount);
      count.push_back(ncount2);
    }
  }
  answer = *min_element(count.begin(), count.end());
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