#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(int n)
{
  string answer = "";
  vector<string> pattern = {"��", "��"};
  for (int i = 0; i < n; i++)
  {
    answer += pattern[i % 2];
  }
  return answer;
}