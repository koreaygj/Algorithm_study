#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b)
{
  string answer = "";
  vector<int> day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<string> d_week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
  int count = -1;
  for (int i = 0; i < (a - 1); i++)
  {
    count += day[i];
  }
  count = (count + b) % 7;
  answer = d_week[count];
  return answer;
}
int main(void)
{
  int a = 6;
  int b = 24;
  cout << solution(a, b);
  return 0;
}