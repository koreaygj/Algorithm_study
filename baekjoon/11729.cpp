#include <iostream>
using namespace std;
void solution(int k, int start, int to, int pass)
{
  if (k == 1)
    cout << start << " " << to << "\n";
  else
  {
    solution(k - 1, start, pass, to);
    cout << start << " " << to << "\n";
    solution(k - 1, pass, to, start);
  }
}
int main(void)
{
  int k = 0;
  cin >> k;
  cout << (1 << k) - 1 << "\n";
  solution(k, 1, 3, 2);
  return 0;
}