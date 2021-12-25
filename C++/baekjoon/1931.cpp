#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool grid(vector<int> a, vector<int> b)
{
 if (a[0] == b[0])
  return a[1] < b[1];
 return a[0] < b[0];
}
int main(void)
{
 int n;
 int answer = 1;
 cin >> n;
 int init, fin, thm;
 int prev = 1;
 vector<vector<int>> meet(100001, vector<int>(3, 0));
 vector<int> arr_fin(100001, 0);
 for (int i = 1; i <= n; i++)
 {
  cin >> init >> fin;
  thm = fin - init;
  meet[i] = {init, fin, thm};
  arr_fin[i] = fin;
 }
 sort(meet.begin() + 1, meet.begin() + 1 + n, grid);
 for (int i = 1; i < n; i++)
 {
  cout << endl;
  if (meet[i][1] <= meet[i + 1][0])
   answer++;
  else if (meet[i][1] <= meet[i + 1][1])
   swap(meet[i], meet[i + 1]);
  for (int i = 1; i <= n; i++)
   cout << meet[i][0] << " " << meet[i][1] << " " << meet[i][2] << endl;
 }
 cout << answer << "\n";
 return 0;
}