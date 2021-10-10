#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
  bool answer = true;
  sort(phone_book.begin(), phone_book.end());
  for (int i = 0; i < phone_book.size(); i++)
  {
    for (int k = i + 1; k < phone_book.size(); k++)
    {
      for (int j = 0; j < phone_book[i].size(); j++)
      {
        if (phone_book[i].at(j) == phone_book[k].at(j))
        {
          answer = false;
        }
        else
        {
          answer = true;
          break;
        }
      }
<<<<<<< HEAD
=======
      cout << answer << " ";
>>>>>>> bce537f0ff0952591dd21e19c7ba62bc681517ae
      if (answer == false)
      {
        break;
      }
    }
    if (answer == false)
      break;
  }
  return answer;
}
int main(void)
{
  vector<string> phone_book = {"12", "123", "1235", "567", "88"};
  cout << solution(phone_book);
  return 0;
}