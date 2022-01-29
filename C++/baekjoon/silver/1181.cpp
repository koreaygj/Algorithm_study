#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class word
{
public:
  string s;
  int size;
};
bool comp(word a, word b)
{
  if (a.size == b.size)
    return a.s < b.s;
  return a.size < b.size;
}
int main(void)
{
  int n;
  cin >> n;
  vector<word> input;
  for (int i = 0; i < n; i++)
  {
    string a;
    cin >> a;
    int b = a.size();
    input.push_back({a, b});
  }
  sort(input.begin(), input.end(), comp);
  cout << input[0].s << "\n";
  for (int i = 1; i < n; i++)
  {
    if (input[i - 1].s != input[i].s)
      cout << input[i].s << "\n";
  }
  return 0;
}