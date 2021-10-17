#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
  int answer = 0;
  for (int i = 0; i < signs.size(); i++)
  {
    answer += signs[i] ? absolutes[i] : -absolutes[i];
  }
  return answer;
}
int main(void)
{
  vector<int> num = {4, 7, 12};
  vector<bool> sign = {true, false, true};
  cout << solution(num, sign);
  return 0;
}