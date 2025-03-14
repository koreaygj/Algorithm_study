#include <algorithm>
#include <iostream>
using namespace std;
// WASD
pair<int, int> Move(int d, int cmd, pair<int, int> cur) {
  // W: 0, A: 1, S: 2, D:3
  int move[4][4][2] = {{{0, 1}, {-1, 0}, {0, -1}, {1, 0}},
                       {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
                       {{0, -1}, {1, 0}, {0, 1}, {-1, 0}},
                       {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
  return make_pair(cur.first + move[d][cmd][0], cur.second + move[d][cmd][1]);
}
// camera move
// 사람을 중심으로 생각
// MR: 0, ML: 1
pair<int, int> CalculateCameraPosition(int direction,
                                       pair<int, int> playerPos) {
  int cameraOffset[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  return make_pair(playerPos.first + cameraOffset[direction][0],
                   playerPos.second + cameraOffset[direction][1]);
}
// camera direction
// MR: 0, ML: 1
// 카메라 방향   0: ⬆ 1: ➡ 2: ⬇ 3: ⬅
int NextCameraDirection(int currentDirection, int rotateCmd) {
  if (rotateCmd == 0) {
    return (currentDirection + 1) % 4;
  } else {
    return (currentDirection + 3) % 4;
  }
}
int main() {
  int n;
  cin >> n;
  pair<int, int> user;
  pair<int, int> camera;
  int ans[n][4];
  user = make_pair(0, 0);
  camera = make_pair(0, -1);
  // 카메라 방향 0: ⬆ 1: ➡ 2: ⬇ 3: ⬅
  int direction = 0;
  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd.length() > 1) {
      direction = NextCameraDirection(direction, cmd == "ML");
      camera = CalculateCameraPosition(direction, user);
    } else {
      int moveCmd;
      if (cmd == "W")
        moveCmd = 0;
      else if (cmd == "A")
        moveCmd = 1;
      else if (cmd == "S")
        moveCmd = 2;
      else
        moveCmd = 3;
      user = Move(direction, moveCmd, user);
      camera = Move(direction, moveCmd, camera);
    }
    ans[i][0] = user.first;
    ans[i][1] = user.second;
    ans[i][2] = camera.first;
    ans[i][3] = camera.second;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " "
         << ans[i][3] << "\n";
}