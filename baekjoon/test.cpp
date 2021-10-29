#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  vector<vector<string>> a = {{"*", "*", "*"}, {"*", " ", "*"}, {"*", "*", "*"}};
  vector<vector<string>> b = {{"*", "*", "*"}, {"*", " ", "*"}, {"*", "*", "*"}};
  for (int i = 0; i < 3; i++)
  {
    a[i].insert(a[i].end(), b[i].begin(), b[i].end());
  }
  for (int i = 0; i < 2; i++)
    a.insert(a.end(), a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size() + a.size(); j++)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}