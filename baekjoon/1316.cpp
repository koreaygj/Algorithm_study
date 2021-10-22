#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(vector<string> s)
{
  int answer = 0;
  string str = "";
  bool flag = false;
  for (int i = 0; i < s.size(); i++)
  {
    str = "";
    flag = true;
    for (int j = 0; j < s[i].size(); j++)
    {
      if (str.back() != s[i][j])
        str += s[i][j];
    }
    for (int j = 0; j < str.size(); j++)
    {
      for (int k = j + 1; k < str.size(); k++)
      {
        if (str[j] == str[k])
        {
          flag = false;
          break;
        }
      }
    }
    if (flag == true)
      answer++;
  }
  return answer;
}
int main(void)
{
  int n = 0;
  vector<string> str;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    str.push_back(s);
    cin.ignore();
  }
  cout << solution(str);
  return 0;
}