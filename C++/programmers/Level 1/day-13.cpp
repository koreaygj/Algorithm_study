#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s)
{
  string answer = "";
  int c = 'A' - 'a';
  int index = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (index % 2 == 0)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
        answer += s[i] + c;
      else
        answer += s[i];
    }
    else
    {
      if (s[i] >= 'A' && s[i] <= 'Z')
        answer += s[i] - c;
      else
        answer += s[i];
    }
    if (s[i] == ' ')
    {
      index = -1;
    }
    index++;
  }
  return answer;
}
int main(void)
{
  string s = "Hello eVeryone";
  cout << solution(s);
  return 0;
}