import java.util.*;

public class Main {
  static int N;
  static int M;
  static int answer;
  static int[][] Paper = new int[301][301];

  public static void dfs(int y, int x, int cnt, int sum, boolean[][] visited) {
    int[] directionY = { 0, 1, 0, -1 };
    int[] directionX = { 1, 0, -1, 0 };
    if (cnt >= 4) {
      answer = Math.max(sum, answer);
      return;
    }
    for (int i = 0; i < 4; i++) {
      int nextY = y + directionY[i];
      int nextX = x + directionX[i];
      if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M || visited[nextY][nextX])
        continue;
      visited[nextY][nextX] = true;
      dfs(nextY, nextX, cnt + 1, sum + Paper[nextY][nextX], visited);
      visited[nextY][nextX] = false;
    }
  }

  public static void check(int y, int x) {
    if (y < N - 2 && x < M - 1)
      answer = Math.max(answer, Paper[y][x] + Paper[y + 1][x] + Paper[y + 2][x] + Paper[y + 1][x + 1]);

    if (y < N - 2 && x > 0)
      answer = Math.max(answer, Paper[y][x] + Paper[y + 1][x] + Paper[y + 2][x] + Paper[y + 1][x - 1]);

    if (y < N - 1 && x < M - 2)
      answer = Math.max(answer, Paper[y][x] + Paper[y][x + 1] + Paper[y][x + 2] + Paper[y + 1][x + 1]);

    if (y > 0 && x < M - 2)
      answer = Math.max(answer, Paper[y][x] + Paper[y][x + 1] + Paper[y][x + 2] + Paper[y - 1][x + 1]);
  }

  public static void solution() {
    boolean visited[][] = new boolean[501][501];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        visited[i][j] = true;
        dfs(i, j, 1, Paper[i][j], visited);
        visited[i][j] = false;
        check(i, j);
      }
    }
    return;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    Paper = new int[501][501];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        Paper[i][j] = sc.nextInt();
      }
    }
    sc.close();
    solution();
    System.out.println(answer);
  }
}