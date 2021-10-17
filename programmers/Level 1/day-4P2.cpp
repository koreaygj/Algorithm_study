#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
int N;
using namespace std;
bool cmp(string a, string b)
{
  int n = N;
  if (a.at(n) != b.at(n))
  {
    return a.at(n) < b.at(n);
  }
  else
  {
    return a < b;
  }
}
vector<string> solution(vector<string> strings, int n)
{
  vector<string> answer;
  N = n;
  sort(strings.begin(), strings.end(), cmp);
  answer = strings;
  return answer;
}
int main(void)
{
  vector<string> strings = {"sun", "bec", "car"};
  int i = 1;
  vector<string> answer = solution(strings, i);
  return 0;
}