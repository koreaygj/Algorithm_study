#include <iostream>
#include <vector>
using namespace std;
class sol
{
public:
  int count;
  int zero;
  int one;
};
vector<sol> memo(100, {0, 0, 0});
sol fibonacci(int n)
{
  if (n == 0)
  {
    memo[n].zero = 1;
    return memo[n];
  }
  else if (n == 1)
  {
    memo[n].one = 1;
    return memo[n];
  }
  else if (memo[n].count != 0)
  {
    return memo[n];
  }
  else
  {
    sol a, b;
    a = fibonacci(n - 1);
    b = fibonacci(n - 2);
    memo[n].count = a.count + b.count;
    memo[n].zero = a.zero + b.zero;
    memo[n].one = a.one + b.one;
    return memo[n];
  }
}
int main(void)
{

  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    fibonacci(n);
    cout << memo[n].zero << " " << memo[n].one << "\n";
  }
  return 0;
}