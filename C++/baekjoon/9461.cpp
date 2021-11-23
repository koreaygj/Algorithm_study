#include <iostream>
#include <vector>
using namespace std;
vector<long long int> pattern(101, 0);
int a;
void solution(int count)
{
  if (pattern[a] != 0)
    return;
  if (count - 1 == a)
    return;
  pattern[count] = pattern[count - 5] + pattern[count - 1];
  solution(count + 1);
}
int main(void)
{
  int n;
  cin >> n;
  pattern[1] = 1;
  pattern[2] = 1;
  pattern[3] = 1;
  pattern[4] = 2;
  pattern[5] = 2;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a > 5)
      solution(6);
    cout << pattern[a] << "\n";
  }
  return 0;
}