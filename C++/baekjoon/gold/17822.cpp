#include <algorithm>
#include <iostream>
using namespace std;
int N, M;
int RoundBoard[51][51];
void Rotate(int x, int d, int k) {
  int temp[M];
  for (int i = 0; i < M; i++) {
    if (d == 0)
      temp[i] = RoundBoard[x][(i - k + M) % M];
    else
      temp[i] = RoundBoard[x][(i + k) % M];
  }
  for (int i = 0; i < M; i++) RoundBoard[x][i] = temp[i];
}
bool RemoveNum() {
  int dy[] = {1, -1, 0, 0};
  int dx[] = {0, 0, 1, -1};
  int cnt = 0;
  bool temp[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      temp[i][j] = false;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int cur = RoundBoard[i][j];
      if (cur == 0) continue;
      for (int k = 0; k < 4; k++) {
        if (i + dy[k] < 0 || i + dy[k] >= N) continue;
        int adjoin = RoundBoard[i + dy[k]][(j + dx[k] + M) % M];
        if (cur == adjoin) {
          temp[i][j] = true;
          temp[i + dy[k]][(j + dx[k] + M) % M] = true;
          cnt++;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!temp[i][j]) continue;
      RoundBoard[i][j] = 0;
    }
  }
  return cnt > 0;
}
void CalAvg() {
  double sum = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (RoundBoard[i][j] > 0) {
        cnt++;
        sum += RoundBoard[i][j];
      }
    }
  }
  double avg = (double)sum / cnt;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      if (RoundBoard[i][j] > 0) {
        if (RoundBoard[i][j] > avg)
          RoundBoard[i][j]--;
        else if (RoundBoard[i][j] < avg)
          RoundBoard[i][j]++;
      }
  }
}
int CalSum() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      sum += RoundBoard[i][j];
    }
  }
  return sum;
}
int main() {
  int t;
  cin >> N >> M >> t;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> RoundBoard[i][j];
  }
  for (int i = 0; i < t; i++) {
    int x, d, k;
    cin >> x >> d >> k;
    for (int j = x; j <= N; j += x) Rotate(j - 1, d, k);
    if (!RemoveNum()) CalAvg();
  }
  int ans = CalSum();
  cout << ans << "\n";
}