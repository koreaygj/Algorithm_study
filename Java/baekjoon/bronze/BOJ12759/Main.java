package Java.baekjoon.bronze.BOJ12759;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int firstPlayer = sc.nextInt();
    int secondPlayer = firstPlayer == 1 ? 2 : 1;
    int[][] board = new int[4][4];
    int answer = 0;
    for (int i = 0; i < 9; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      if (answer != 0)
        continue;
      if (i % 2 == 0) {
        board[x][y] = firstPlayer;
        if (checkEnd(board, firstPlayer))
          answer = firstPlayer;
      } else {
        board[x][y] = secondPlayer;
        if (checkEnd(board, secondPlayer))
          answer = secondPlayer;
      }
    }
    sc.close();
    System.out.println(answer);
    return;
  }

  static boolean checkEnd(int[][] board, int playerNum) {
    // 가로 확인
    for (int i = 1; i <= 3; i++) {
      int count = 0;
      for (int j = 1; j <= 3; j++) {
        if (board[i][j] == playerNum)
          count++;
      }
      if (count == 3)
        return true;
    }
    // 세로 확인
    for (int i = 1; i <= 3; i++) {
      int count = 0;
      for (int j = 1; j <= 3; j++) {
        if (board[j][i] == playerNum)
          count++;
      }
      if (count == 3)
        return true;
    }
    // 대각선 확인
    if (board[1][1] == playerNum && board[2][2] == playerNum && board[3][3] == playerNum)
      return true;
    if (board[1][3] == playerNum && board[2][2] == playerNum && board[3][1] == playerNum)
      return true;
    return false;
  }
}
