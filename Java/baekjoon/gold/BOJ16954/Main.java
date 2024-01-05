package Java.baekjoon.gold.BOJ16954;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
  static String[] Board = new String[8];

  static class Point {
    int x;
    int y;
    int time;

    public Point(int x, int y, int time) {
      this.x = x;
      this.y = y;
      this.time = time;
    }

  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    for (int i = 0; i < 8; i++) {
      Board[i] = br.readLine();
    }
    System.out.println(solution() ? "1" : "0");
  }

  // 벽들을 한칸씩 내리기
  // 맨밑의 보드를 삭제후 한칸씩 내리기
  // 그후 빈 ........ 맨 위에 추가
  static void moveWalls() {
    for (int i = 7; i > 0; i--) {
      Board[i] = Board[i - 1];
    }
    Board[0] = "........";
  }

  static boolean solution() {
    Queue<Point> q = new LinkedList<>();
    boolean[][] visited = new boolean[8][8];
    q.add(new Point(7, 0, 0));
    visited[7][0] = true;
    int curTime = 0;
    while (!q.isEmpty()) {
      Point cur = q.poll();
      // 도착한 경우 true
      if (cur.x == 0 && cur.y == 7)
        return true;
      // 현재 시간과 queue에서 뺀 시간이 다른 경우 보드의 벽을 아래로 내리기
      if (curTime != cur.time) {
        moveWalls();
        curTime = cur.time;
        // 벽을 내린 후 움직이는 방향 모두 가능하도록 visited 초기화
        visited = new boolean[8][8];
      }
      // 현재 위치에 벽이 내려온 경우 움직일 수 없다.
      if (Board[cur.x].charAt(cur.y) == '#')
        continue;
      for (int i = 0; i < 8; i++) {
        // 상하좌우 대각선 4방향까지 8방향 판단하기
        int[] moveX = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] moveY = { -1, 0, 1, -1, 1, -1, 0, 1 };
        Point next = new Point(cur.x + moveX[i], cur.y + moveY[i], cur.time + 1);
        // 보드를 벗어나거나, 방문한 경우, 벽이 있는 경우 움직일 수 없는 방향이므로 continue;
        if (next.x < 0 || next.x >= 8 || next.y < 0 || next.y >= 8 || visited[next.x][next.y]
            || Board[next.x].charAt(next.y) == '#')
          continue;
        // 다음 방향 방문 처리 및 queue에 추가
        visited[next.x][next.y] = true;
        q.add(next);
      }
      // 가만히 있는 경우 현재 point에서 시간만 1번 더해준 후 queue에 추가
      cur.time++;
      q.add(cur);
    }
    return false;
  }

}
