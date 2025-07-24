#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main() {
  fastio;
  int n, score, p;
  cin >> n >> score >> p;

  int record[50];
  if (n == 0) {
    cout << "1\n";
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> record[i];
  sort(record, record + n, greater<int>());

  int rank = 1;
  for (int i = 0; i < n; i++) {
    if (record[i] > score) {
      rank++;
    } else {
      break;
    }
  }

  if (rank > p) {
    cout << "-1\n";
  } else if (n >= p && record[rank - 1] == score && record[p - 1] >= score) {
    cout << "-1\n";
  } else {
    cout << rank << "\n";
  }

  return 0;
}