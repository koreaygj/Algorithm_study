#include <iostream>
#include <vector>
using namespace std;
vector<long long int> memo(1000001, 0);
long long int solution(int count)
{
  if (memo[count] != 0)
    return memo[count];
  if (count == 2)
  {
    memo[count] = 2 % 15746;
    return 2;
  }
  else if (count == 1)
  {
    memo[count] = 1 % 15746;
    return 1;
  }
  else if (count >= 3)
  {
    memo[count] = (solution(count - 1) + solution(count - 2)) % 15746;
    return memo[count];
  }
}
int main(void)
{
  long long int answer = 0;
  long long int n;
  cin >> n;
  answer = solution(n);
  cout << answer << "\n";
  return 0;
}