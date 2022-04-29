#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Member
{
public:
  int rank;
  int age;
  string name;
};
bool comp(Member a, Member b)
{
  if (a.age == b.age)
    return a.rank < b.rank;
  return a.age < b.age;
}
int main(void)
{
  int n;
  cin >> n;
  vector<Member> input;
  for (int i = 0; i < n; i++)
  {
    string a;
    int age;
    cin >> age;
    cin >> a;
    input.push_back({i, age, a});
  }
  sort(input.begin(), input.end(), comp);
  for (int i = 0; i < n; i++)
  {
    cout << input[i].age << " " << input[i].name << "\n";
  }
  return 0;
}