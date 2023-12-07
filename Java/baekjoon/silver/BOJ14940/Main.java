package Java.baekjoon.silver.BOJ14940;

import java.util.*;
import java.io.*;

public class Main {
  static int[][] Map = new int[1001][1001];

  static class Point {
    int y;
    int x;

    public Point(int y, int x) {
      this.y = y;
      this.x = x;

    }
  }

  static void solution(int stY, int stX, int n, int m) {
    boolean[][] visited = new boolean[1001][1001];
    Queue<Point> q = new LinkedList<>();
    q.add(new Point(stY, stX));
    Map[stY][stX] = 0;
    visited[stY][stX] = true;
    while (!q.isEmpty()) {
      Point cur = q.poll();
      for (int i = 0; i < 4; i++) {
        int[] moveY = { -1, 1, 0, 0 };
        int[] moveX = { 0, 0, -1, 1 };
        Point next = new Point(cur.y + moveY[i], cur.x + moveX[i]);
        if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || visited[next.y][next.x]
            || Map[next.y][next.x] == 0)
          continue;
        visited[next.y][next.x] = true;
        Map[next.y][next.x] = Map[cur.y][cur.x] + 1;
        q.add(next);
      }
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int stY = 0;
    int stX = 0;
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        Map[i][j] = Integer.parseInt(st.nextToken());
        if (Map[i][j] == 2) {
          stY = i;
          stX = j;
        }
        if (Map[i][j] == 1)
          Map[i][j] = -1;
      }
    }
    solution(stY, stX, n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        System.out.print(Map[i][j] + " ");
      System.out.println();
    }
  }
}
