#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
vector<int> oper, order;
int max, min;
int main(void)
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int n, k;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    num.push_back(a);
    order.push_back(0);
  }
  for (int i = 0; i < 4; i++)
  {
    int b;
    cin >> b;
    oper.push_back(b);
  }
  return 0;
}