#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long int solution(vector<long int> a, long int b, long int c)
{
  long int answer = a.size();
  long double sum = 0;
  for (int i = 0; i < a.size(); i++)
  {
    sum = a[i] - b;
    if (sum > 0)
      answer += ceil(sum / c);
  }
  return answer;
}
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long int n, s, b, c;
  vector<long int> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    a.push_back(s);
  }
  cin >> b >> c;
  cout << solution(a, b, c);
  return 0;
}