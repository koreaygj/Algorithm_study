#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int solution(string s)
{
  int answer = 0;
  answer = atoi(s.c_str());
  return answer;
}
int main(void)
{
  string a = "1234";
  cout << solution(a);
  return 0;
}