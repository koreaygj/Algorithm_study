package Java.baekjoon.gold.BOJ4178;

import java.util.*;

public class Main {
  static char[][] Map = new char[1001][1001];
  static int R;
  static int C;

  static class Point {
    int y;
    int x;
    int cnt = 0;

    public Point(int y, int x, int cnt) {
      this.y = y;
      this.x = x;
      this.cnt = cnt;
    }
  }

  // 불이 움직임을 시간으로 표시하는 메서드
  static int[][] spreadFire() {
    int[][] burned = new int[1001][1001];
    boolean[][] visited = new boolean[1001][1001];

    Queue<Point> fire = new LinkedList<>();
    // 처음 시작하는 불의 위치
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (Map[i][j] == 'F') {
          visited[i][j] = true;
          burned[i][j] = 1;
          fire.add(new Point(i, j, 1));
        }
      }
    }
    // 이후 움직이는 불의 위치 기록
    while (!fire.isEmpty()) {
      Point curFire = fire.poll();
      int[] moveY = { -1, 1, 0, 0 };
      int[] moveX = { 0, 0, -1, 1 };
      for (int i = 0; i < 4; i++) {
        Point nextFire = new Point(curFire.y + moveY[i], curFire.x + moveX[i], curFire.cnt + 1);
        if (nextFire.y < 0 || nextFire.y >= R || nextFire.x < 0 || nextFire.x >= C || visited[nextFire.y][nextFire.x])
          continue;
        if (Map[nextFire.y][nextFire.x] == '.') {
          visited[nextFire.y][nextFire.x] = true;
          fire.add(nextFire);
          burned[nextFire.y][nextFire.x] = nextFire.cnt;
        }
      }
    }
    return burned;
  }

  static void solution(Point st) {
    Queue<Point> path = new LinkedList<>();
    boolean[][] visited = new boolean[1001][1001];
    int[][] burned = spreadFire();
    // 처음 지훈이의 위치
    path.add(st);
    visited[st.y][st.x] = true;

    // 지훈이가 움직이는 방향을 기록
    while (!path.isEmpty()) {
      Point curPoint = path.poll();
      for (int i = 0; i < 4; i++) {
        int[] moveY = { -1, 1, 0, 0 };
        int[] moveX = { 0, 0, -1, 1 };
        Point nextPoint = new Point(curPoint.y + moveY[i], curPoint.x + moveX[i], curPoint.cnt + 1);

        // 미로를 벗어나는 경우 걸린 시간 출력
        if (nextPoint.y < 0 || nextPoint.y >= R || nextPoint.x < 0 || nextPoint.x >= C) {
          System.out.println(curPoint.cnt);
          return;
        }
        // 가려고 하는 위치가 벽이 있거나 방문한 경우 지나치기
        if (Map[nextPoint.y][nextPoint.x] == '#' || visited[nextPoint.y][nextPoint.x])
          continue;
        // 불에 탄 위치인 경우 현재 시간보다 이전인지 이후인지 확인
        if (burned[nextPoint.y][nextPoint.x] <= nextPoint.cnt && burned[nextPoint.y][nextPoint.x] != 0)
          continue;
        visited[nextPoint.y][nextPoint.x] = true;
        path.add(nextPoint);
      }
    }
    System.out.println("IMPOSSIBLE");
  }

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    R = sc.nextInt();
    C = sc.nextInt();
    sc.nextLine();
    int x = 0, y = 0;
    // 입력받기
    for (int i = 0; i < R; i++) {
      String tmp = sc.nextLine();
      for (int j = 0; j < C; j++) {
        Map[i][j] = tmp.charAt(j);
        if (Map[i][j] == 'J') {
          y = i;
          x = j;
        }
      }
    }
    sc.close();
    solution(new Point(y, x, 1));
  }
}