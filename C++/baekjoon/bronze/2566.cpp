#include <iostream>
using namespace std;
int main() {
  int max = -1;
  pair<int, int> coord;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int tmp;
      cin >> tmp;
      if (max < tmp) {
        max = tmp;
        coord = make_pair(i + 1, j + 1);
      }
    }
  }
  cout << max << "\n";
  cout << coord.first << " " << coord.second << "\n";
}