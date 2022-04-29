#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(string s, int n)
{
  string answer = "";
  string a = "";
  vector<string> code = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
  vector<string> code2 = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  for (int i = 0; i < s.size(); i++)
  {
    a = s.at(i);
    for (int j = 0; j < code.size(); j++)
    {
      if (a == code[j])
      {
        if ((j + n) <= 25)
        {
          answer += code[j + n];
          break;
        }
        else
        {
          answer += code[j + n - 26];
          break;
        }
      }
      if (a == code2[j])
      {
        if ((j + n) <= 25)
        {
          answer += code2[j + n];
          break;
        }
        else
        {
          answer += code2[j + n - 26];
          break;
        }
      }
      if (a == " ")
      {
        answer += " ";
        break;
      }
    }
  }
  return answer;
}
int main(void)
{
  string s = {"XY"};
  int n = 1;
  cout << solution(s, n);
  return 0;
}