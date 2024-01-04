package Java.baekjoon.gold.BOJ2140;

import java.util.Scanner;

public class Main {
  static char[][] Board = new char[101][101];
  static int N;
  static int Count;

  static int solution(int x, int y) {
    int[] moveX = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int[] moveY = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 8; i++) {
      int nextX = x + moveX[i];
      int nextY = y + moveY[i];
      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        continue;
      if (Board[nextX][nextY] == '0') {
        return 0;
      }
    }
    for (int i = 0; i < 8; i++) {
      int nextX = x + moveX[i];
      int nextY = y + moveY[i];
      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
        continue;
      if (Board[nextX][nextY] != '#') {
        Board[nextX][nextY]--;
      }
    }
    return 1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    for (int i = 0; i < N; i++) {
      String tmp = sc.next();
      for (int j = 0; j < N; j++)
        Board[i][j] = tmp.charAt(j);
    }
    sc.close();
    int mine = 0;
    for (int i = 1; i < N - 1; i++) {
      for (int j = 1; j < N - 1; j++) {
        mine += solution(i, j);
      }
    }
    System.out.println(mine);
  }
}