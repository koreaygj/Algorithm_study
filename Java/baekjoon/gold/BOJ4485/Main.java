package Java.baekjoon.gold.BOJ4485;

import java.util.*;

public class Main {
  static int[][] Cave = new int[126][126];

  static class Point {
    int x;
    int y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int cnt = 1;
    // 입력
    while (true) {
      int n = sc.nextInt();
      if (n == 0)
        break;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          Cave[i][j] = sc.nextInt();
      }
      solution(n, cnt++);
    }
    sc.close();
  }

  static void solution(int n, int cnt) {
    Queue<Point> q = new LinkedList<>();
    // 방문했는지 확인과 현재 위치에서의 최솟값 저장 배열
    int[][] memo = new int[n][n];
    // 배열 -1로 초기화 방문 확인을 위해
    for (int i = 0; i < n; i++)
      Arrays.fill(memo[i], -1);
    q.add(new Point(0, 0));
    memo[0][0] = Cave[0][0];
    while (!q.isEmpty()) {
      Point cur = q.poll();
      for (int i = 0; i < 4; i++) {
        int[] nextX = { 0, 0, -1, 1 };
        int[] nextY = { -1, 1, 0, 0 };
        Point next = new Point(cur.x + nextX[i], cur.y + nextY[i]);
        // 주어진 배열을 벗어나면 continue
        if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n)
          continue;
        // 방문했을 때의 cost가 더 적다면 continue
        if (memo[next.x][next.y] <= memo[cur.x][cur.y] + Cave[next.x][next.y] && memo[next.x][next.y] != -1)
          continue;
        // 더 작은 cost로 갱신
        memo[next.x][next.y] = memo[cur.x][cur.y] + Cave[next.x][next.y];
        q.add(next);
      }
    }
    // 도착점에 저장된 최솟값 출력
    System.out.println("Problem " + cnt + ": " + memo[n - 1][n - 1]);
  }
}