#include <iostream>
#include <string>
using namespace std;
bool solution(string s)
{
  bool answer = true;
  int a = 0;
  int b = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s.at(i) == 'y' || s.at(i) == 'Y')
      a++;
    if (s.at(i) == 'p' || s.at(i) == 'P')
      b++;
  }
  if (a != b)
    answer = false;
  return answer;
}
int main(void)
{
  string s = "pPoooyY";
  return 0;
}