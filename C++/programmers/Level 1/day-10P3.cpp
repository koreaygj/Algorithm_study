#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<vector<int>> scores)
{
  string answer = "";
  int avr = 0;
  int mine = 0;
  int max = 0;
  int min = 0;
  for (int i = 0; i < scores[0].size(); i++)
  {
    mine = scores[i][i];
    for (int j = 0; j < scores[0].size(); j++)
    {
      if (mine > scores[j][i])
        max++;
      if (mine < scores[j][i])
        min++;
      avr += scores[j][i];
    }
    if (max == (scores.size() - 1) || min == (scores.size() - 1))
    {
      avr -= mine;
      avr = avr / (scores.size() - 1);
    }
    else
      avr = avr / scores.size();
    cout << avr / 10 << " ";
    switch (avr / 10)
    {
    case 10:
      answer += "A";
      break;
    case 9:
      answer += "A";
      break;
    case 8:
      answer += "B";
      break;
    case 7:
      answer += "C";
      break;
    case 6:
      answer += "D";
      break;
    case 5:
      answer += "D";
      break;
    default:
      answer += "F";
      break;
    }
    avr = 0;
    max = 0;
    min = 0;
  }
  return answer;
}
int main(void)
{
  vector<vector<int>> score = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}};
  cout << solution(score);
  return 0;
}