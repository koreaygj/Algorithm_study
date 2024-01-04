#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class dress
{
public:
 string type;
 int num;
};
int main(void)
{
 int t;
 cin >> t;
 for (int i = 0; i < t; i++)
 {
  int n;
  int answer = 1;
  cin >> n;
  vector<dress> count(n, {"", 1});
  for (int j = 0; j < n; j++)
  {
   string a, b;
   cin >> a >> b;
   for (int k = 0; k < n; k++)
   {
    if (count[k].type == "")
    {
     count[k].type = b;
     count[k].num++;
     break;
    }
    if (b == count[k].type)
    {
     count[k].num++;
     break;
    }
   }
  }
  for (int j = 0; j < n; j++)
  {
   answer *= count[j].num;
  }
  cout << answer - 1 << "\n";
 }
 return 0;
}