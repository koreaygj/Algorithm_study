#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
  int answer = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'c')
    {
      if (s[i + 1] == '=' || s[i + 1] == '-')
        i++;
    }
    else if (s[i] == 'd')
    {
      if (s[i + 1] == 'z' && s[i + 2] == '=')
        i += 2;
      if (s[i + 1] == '-')
        i++;
    }
    else if ((s[i] == 'l' && s[i + 1] == 'j') || (s[i] == 'n' && s[i + 1] == 'j') || (s[i] == 's' && s[i + 1] == '=') || (s[i] == 'z' && s[i + 1] == '='))
    {
      i++;
    }
    answer++;
  }
  return answer;
}
int main(void)
{
  string s;
  getline(cin, s);
  cout << solution(s);
  return 0;
}