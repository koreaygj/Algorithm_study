#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s)
{
  string answer = "";
  vector<char> str;
  for (int i = 0; i < s.size(); i++)
  {
    str.push_back(s.at(i));
  }
  sort(str.begin(), str.end(), greater<int>());
  for (int i = 0; i < str.size(); i++)
  {
    answer += str[i];
  }
  return answer;
}
int main(void)
{
  string s = "Zbcdefg";
  cout << solution(s);
  return 0;
}