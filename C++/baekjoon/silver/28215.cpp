#include <algorithm>
#include <iostream>
#define cal_dist(a, b, c, d) (abs(a - c) + abs(b - d))
using namespace std;
int N, K;
int House[51][2];
bool SelectNum[51];
int Ans = 987654321;
// find minimum dist
void FindMin(int comb[3]) {
  int a = comb[0], b = comb[1], c = comb[2];
  if (K == 1) {
    b = a;
    c = a;
  } else if (K == 2)
    c = b;
  int result = 0;
  for (int i = 0; i < N; i++) {
    int min_dist =
        min(min(cal_dist(House[i][0], House[i][1], House[a][0], House[a][1]),
                cal_dist(House[i][0], House[i][1], House[b][0], House[b][1])),
            cal_dist(House[i][0], House[i][1], House[c][0], House[c][1]));
    result = min_dist > result ? min_dist : result;
  }
  Ans = result < Ans ? result : Ans;
}
// Combination
void Combination(int comb[3], int depth) {
  if (depth == K) {
    FindMin(comb);
    return;
  }
  for (int i = 0; i < N; i++) {
    if (SelectNum[i]) continue;
    SelectNum[i] = true;
    comb[depth] = i;
    Combination(comb, depth + 1);
    SelectNum[i] = false;
  }
}
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> House[i][0] >> House[i][1];
  }
  if (K == N) {
    cout << "0\n";
    return 0;
  }
  int comb[3];
  Combination(comb, 0);
  cout << Ans << "\n";
}