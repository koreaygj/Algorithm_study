#include <algorithm>
#include <iostream>
#include <vector>

#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define MAX 101

using namespace std;

int C, P;
int heights[MAX];
int result = 0;
void checkTetrominoI() {
  result += C;

  for (int i = 0; i <= C - 4; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2] &&
        heights[i + 2] == heights[i + 3]) {
      result++;
    }
  }
}
void checkTetrominoO() {
  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1]) {
      result++;
    }
  }
}
void checkTetrominoZ() {
  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2] - 1) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] + 1) {
      result++;
    }
  }
}
void checkTetrominoS() {
  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] - 1 == heights[i + 1] && heights[i + 1] == heights[i + 2]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] - 1) {
      result++;
    }
  }
}
void checkTetrominoT() {
  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 2] && heights[i + 1] == heights[i] - 1) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] + 1) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] - 1) {
      result++;
    }
  }
}
void checkTetrominoJ() {
  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] - 1 && heights[i + 1] == heights[i + 2]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] + 2) {
      result++;
    }
  }
}
void checkTetrominoL() {
  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2]) {
      result++;
    }
  }

  for (int i = 0; i <= C - 3; i++) {
    if (heights[i] == heights[i + 1] && heights[i + 1] == heights[i + 2] + 1) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1] - 2) {
      result++;
    }
  }

  for (int i = 0; i <= C - 2; i++) {
    if (heights[i] == heights[i + 1]) {
      result++;
    }
  }
}
void solve() {
  switch (P) {
    case 1:
      checkTetrominoI();
      break;
    case 2:
      checkTetrominoO();
      break;
    case 3:
      checkTetrominoZ();
      break;
    case 4:
      checkTetrominoS();
      break;
    case 5:
      checkTetrominoT();
      break;
    case 6:
      checkTetrominoJ();
      break;
    case 7:
      checkTetrominoL();
      break;
  }

  cout << result << endl;
}

int main() {
  FASTIO;
  cin >> C >> P;
  for (int i = 0; i < C; i++) {
    cin >> heights[i];
  }
  solve();
  return 0;
}