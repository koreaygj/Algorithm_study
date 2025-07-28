#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

bool Check_repeat[10];
int Cnt, N, Ans;
bool Find;

void dfs(int index, int cur, int end) {
  if (Find) return;

  if (index == end) {
    Cnt++;
    if (Cnt == N) {
      Ans = cur;
      Find = true;
    }
    return;
  }

  if (index == 0) {
    for (int i = 1; i < 10; i++) {
      if (!Check_repeat[i] && !Find) {
        Check_repeat[i] = true;
        dfs(index + 1, cur * 10 + i, end);
        Check_repeat[i] = false;
      }
    }
  } else {
    for (int i = 0; i < 10; i++) {
      if (!Check_repeat[i] && !Find) {
        Check_repeat[i] = true;
        dfs(index + 1, cur * 10 + i, end);
        Check_repeat[i] = false;
      }
    }
  }
}

int main() {
  fastio;
  while (cin >> N) {
    if (N == 0) break;

    Find = false;
    Cnt = 0;
    Ans = 0;

    for (int i = 1; i <= 10; i++) {
      fill(&Check_repeat[0], &Check_repeat[0] + 10, 0);
      dfs(0, 0, i);
      if (Find) break;
    }

    cout << Ans << "\n";
  }
  return 0;
}