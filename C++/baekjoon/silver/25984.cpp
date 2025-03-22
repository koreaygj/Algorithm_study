#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<vector<pair<int, int>>, int> braille;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<pair<int, int>> coord;
    for (int j = 0; j < m; j++) {
      int a, b;
      cin >> a >> b;
      coord.push_back(make_pair(a, b));
    }
    sort(coord.begin(), coord.end());
    int first_x = coord[0].first;
    int first_y = coord[0].second;
    vector<pair<int, int>> pattern;
    for (int j = 1; j < m; j++) {
      int second_x = coord[j].first;
      int second_y = coord[j].second;
      int sub_x = first_x - second_x;
      int sub_y = first_y - second_y;
      first_x = second_x;
      first_y = second_y;
      pattern.push_back(make_pair(sub_x, sub_y));
    }
    braille.insert({pattern, 1});
  }
  cout << braille.size() << "\n";
}