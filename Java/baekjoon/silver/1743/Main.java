import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
  public static class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int k = sc.nextInt();
    int walkWay[][] = new int[n][m];
    boolean visited[][] = new boolean[n][m];
    int waste[][] = new int[k][2];
    for (int i = 0; i < k; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      waste[i][0] = x - 1;
      waste[i][1] = y - 1;
      walkWay[x - 1][y - 1] = 1;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      int result = bfs(walkWay, visited, waste[i][0], waste[i][1]);
      ans = ans < result ? result : ans;
    }
    System.out.println(ans);
    sc.close();
  }

  static int bfs(int walkWay[][], boolean visited[][], int startX, int startY) {
    if (visited[startX][startY])
      return 1;
    int move[][] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(startX, startY));
    visited[startX][startY] = true;
    int result = 1;
    while (!q.isEmpty()) {
      Pair cur = q.poll();
      for (int i = 0; i < 4; i++) {
        Pair next = new Pair(cur.x + move[i][0], cur.y + move[i][1]);
        if (next.x < 0 || next.x >= walkWay.length || next.y < 0 || next.y >= walkWay[0].length)
          continue;
        if (walkWay[next.x][next.y] == 0 || visited[next.x][next.y])
          continue;
        result++;
        visited[next.x][next.y] = true;
        q.add(next);
      }
    }
    return result;
  }
}