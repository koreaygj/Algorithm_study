#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int solution(int n)
{
  long int answer = 0;
  vector<int> sol;
  while (n != 0)
  {
    sol.push_back(n % 10);
    n /= 10;
  }
  sort(sol.begin(), sol.end());
  for (int i = sol.size() - 1; i >= 0; i--)
  {
    answer += sol[i] * (pow(10, i));
  }
  return answer;
}
int main(void)
{
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}