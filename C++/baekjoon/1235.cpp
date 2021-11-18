#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define Max 100
vector<string> num;
int n;
bool find()
{
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    {
      if (num[i] == num[j])
      {
        return true;
      }
    }
  return false;
}
void solution(int count, bool check)
{
  if (check == true)
  {
    cout << num[0].size() + 1 << "\n";
    return;
  }
  for (int i = 0; i < n; i++)
  {
    num[i] = num[i].substr(1, num[i].size());
  }
  solution(count + 1, find());
}
int main(void)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string a;
    cin >> a;
    num.push_back(a);
  }
  solution(0, false);
  return 0;
}
