#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";
  sort(completion.begin(), completion.end());
  sort(participant.begin(), participant.end());
  for (int j = 0; j < completion.size(); j++)
  {
    if (participant[j] != completion[j])
    {
      answer = participant[j];
      break;
    }
    if (j == participant.size() - 2)
    {
      answer = participant.back();
      break;
    }
  }
  return answer;
}
int main(void)
{
  vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
  vector<string> completion = {"josipa", "filipa", "marina", "nikola"};
  cout << solution(participant, completion);
}