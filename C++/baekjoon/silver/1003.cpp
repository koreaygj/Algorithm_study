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
void fibonacci(int n)
{
  if (n == 0)
  {
    memo[n].count = 0;
    memo[n].zero = 1;
    return;
  }
  else if (n == 1)
  {
    memo[n].count = 1;
    memo[n].one = 1;
    return;
  }
  else if (memo[n].count != 0)
  {
    return;
  }
  else
  {
    fibonacci(n - 1);
    fibonacci(n - 2);
    memo[n].count = memo[n - 1].count + memo[n - 2].count;
    memo[n].zero = memo[n - 1].zero + memo[n - 2].zero;
    memo[n].one = memo[n - 1].one + memo[n - 2].one;
    return;
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