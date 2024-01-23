package Java.baekjoon.gold.BOJ17144;

import java.util.Scanner;

public class Main {
  static int R;
  static int C;
  static int T;
  static int[][] Board = new int[51][51];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    R = sc.nextInt();
    C = sc.nextInt();
    T = sc.nextInt();
    int airConditioner = 0;
    // 입력받기
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        Board[i][j] = sc.nextInt();
        // 공기청정기 아래 좌표
        if (Board[i][j] == -1)
          airConditioner = i;
      }
    }
    sc.close();
    for (int i = 0; i < T; i++) {
      diffuseDirt();
      cleanAir(airConditioner);
    }
    // 남은 미세먼지 수 계산
    int answer = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++)
        if (Board[i][j] != -1)
          answer += Board[i][j];
    }
    System.out.println(answer);
  }

  // 미세먼지 옮기기
  static void diffuseDirt() {
    int[] moveX = { 1, -1, 0, 0 };
    int[] moveY = { 0, 0, 1, -1 };
    // 옮긴 후 미세먼지 변경
    int[][] after = new int[51][51];
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (Board[i][j] <= 0) {
          continue;
        }
        int dirt = Board[i][j];
        int diffuseDirt = dirt / 5;
        for (int k = 0; k < 4; k++) {
          int nextX = i + moveX[k];
          int nextY = j + moveY[k];
          // 보드를 벗어나거나 공기청정기 위치면 건너뛰기
          if (nextX >= R || nextX < 0 || nextY >= C || nextY < 0 || Board[nextX][nextY] == -1)
            continue;
          // 옮겨진 미세먼지 변경점 after배열에 저장
          after[nextX][nextY] += diffuseDirt;
          after[i][j] -= diffuseDirt;
        }
      }
    }
    // 모든 미세먼지 움직임 저장
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        Board[i][j] += after[i][j];
      }
    }
  }

  static void cleanAir(int airConditioner) {
    int top = airConditioner - 1;
    int bottom = airConditioner;
    // 상단 공기 청정
    for (int i = top - 1; i > 0; i--)
      Board[i][0] = Board[i - 1][0];
    for (int i = 0; i < C - 1; i++)
      Board[0][i] = Board[0][i + 1];
    for (int i = 0; i < top; i++)
      Board[i][C - 1] = Board[i + 1][C - 1];
    for (int i = C - 1; i > 1; i--)
      Board[top][i] = Board[top][i - 1];
    // 하단 공기 청정
    for (int i = bottom + 1; i < R; i++)
      Board[i][0] = Board[i + 1][0];
    for (int i = 0; i < C; i++)
      Board[R - 1][i] = Board[R - 1][i + 1];
    for (int i = R - 1; i > bottom; i--)
      Board[i][C - 1] = Board[i - 1][C - 1];
    for (int i = C - 1; i > 1; i--)
      Board[bottom][i] = Board[bottom][i - 1];

    Board[top][1] = 0;
    Board[bottom][1] = 0;
  }
}
