#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul)
{
  string answer = "";
  for (int i = 0; i < seoul.size(); i++)
  {
    if (seoul[i] == "Kim")
    {
      answer = "�輭���� " + to_string(i) + "�� �ִ�";
      break;
    }
  }
  return answer;
}
int main(void)
{
  vector<string> seoul = {"Jane", "Kim"};
  cout << solution(seoul);
  return 0;
}
