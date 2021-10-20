#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long int solution(int n, int m)
{
  long long int answer = 1;
  if (n > m / 2)
    n = m - n;
  for (int i = m; i > m - n; i--)
  {
    answer *= i;
  }
  for (int j = n; j > 0; j--)
  {
    answer /= j;
  }
  return answer;
}
int main(void)
{
  int size = 0;
  vector<long long int> result;
  cin >> size;
  cin.ignore();
  int m, n = 0;
  for (int i = 0; i < size; i++)
  {
    cin >> n >> m;
    result.push_back(solution(n, m));
  }
  for (int i = 0; i < size; i++)
  {
    cout << result[i] << endl;
  }
  return 0;
}