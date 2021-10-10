#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class player
{
public:
  int num;
  int weight;
  double winlate;
  int overspec;
};
bool ranking(player a, player b)
{
  if (a.winlate > b.winlate)
  {
    return true;
  }
  if (a.winlate == b.winlate)
  {
    if (a.overspec > b.overspec)
    {
      return true;
    }
    if (a.overspec == b.overspec)
    {
      if (a.weight > b.weight)
      {
        return true;
      }
      if (a.weight == b.weight && a.num < b.num)
      {
        return true;
      }
    }
  }
  return false;
}
vector<int> solution(vector<int> weights, vector<string> head2head)
{
  vector<int> answer;
  vector<player> boxers;
  for (int i = 0; i < head2head.size(); i++)
  {
    double wins = 0;
    double winlate = 0;
    int overspec = 0;
    double totalsize = 0;
    for (int j = 0; j < head2head[i].length(); j++)
    {
      if (head2head[i][j] == 'N')
      {
        continue;
      }
      if (head2head[i][j] == 'W')
      {
        wins++;
        if (weights[i] < weights[j])
          overspec++;
      }
      totalsize++;
    }
    winlate = wins / totalsize;
    if (wins == 0)
    {
      winlate = 0;
    }
    boxers.push_back({i + 1, weights[i], winlate, overspec});
  }
  sort(boxers.begin(), boxers.end(), ranking);
  for (int k = 0; k < boxers.size(); k++)
  {
    answer.push_back(boxers[k].num);
  }
  return answer;
}
int main(void)
{
  vector<int> weights = {60, 70, 60};
  vector<string> head2head = {"NNN", "NNN", "NNN"};
  vector<int> answer = solution(weights, head2head);
  for (int answer : answer)
  {
    cout << answer << " ";
  }
  cout << "\n";
  return 0;
}