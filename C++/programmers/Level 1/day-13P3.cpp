#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

long long solution(long long n)
{
  long long answer = 0;
  int root = sqrt(n);
  if (n == pow(root, 2))
    answer = pow(root + 1, 2);
  else
    answer = -1;
  return answer;
}
int main(void)
{
  long long n;
  cout << solution(n);
  return 0;
}