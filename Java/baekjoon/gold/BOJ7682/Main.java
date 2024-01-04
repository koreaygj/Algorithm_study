package Java.baekjoon.gold.BOJ7682;

import java.util.*;

public class Main {
  static char[][] board;

  static boolean game() {
    int cntX = 0;
    int cntO = 0;
    // 경우에 수에서 O, X 개수 세기
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        switch (board[i][j]) {
          case 'O':
            cntO++;
            break;
          case 'X':
            cntX++;
            break;
        }
      }
    }
    // O가 X보다 많은 경우는 없으므로 false 리턴
    if (cntO > cntX)
      return false;
    // 보드를 모두 채운 경우 중에 O + 1 = X를 만족하는 경우에서
    if (cntX + cntO == 9 && cntX == cntO + 1) {
      // X 가 승리 , O 가 패배
      if (checkWin('X') && !checkWin('O'))
        return true;
      // X , O 모두 끝내지 못한 경우
      else if (!checkWin('X') && !checkWin('O'))
        return true;
      return false;
    } else { // 보드를 모두 채우지 못한 경우
      // X가 이기고 O이 이기지 못한 경우
      if (checkWin('X') && !checkWin('O'))
        return cntX == cntO + 1;
      // O가 이기고 X이 이기지 못한 경우
      else if (checkWin('O') && !checkWin('X'))
        return cntX == cntO;
      return false;
    }
  }

  // type에 따른 승리 확인하기
  static boolean checkWin(char type) {
    // - 가로 방향
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == type && board[i][1] == type && board[i][2] == type)
        return true;
    }
    // | 세로 방향
    for (int i = 0; i < 3; i++) {
      if (board[0][i] == type && board[1][i] == type && board[2][i] == type)
        return true;
    }
    // \ 대각선
    if (board[0][0] == type && board[1][1] == type && board[2][2] == type)
      return true;
    // / 대각선
    if (board[0][2] == type && board[1][1] == type && board[2][0] == type)
      return true;
    return false;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String tmp = "";
    // 입력 받기
    while (true) {
      tmp = sc.nextLine();
      if (tmp.equals("end"))
        break;
      board = new char[3][3];
      for (int i = 0; i < tmp.length(); i++) {
        board[i / 3][i % 3] = tmp.charAt(i);
      }
      // 케이스에 대한 출력
      String answer = game() ? "valid" : "invalid";
      System.out.println(answer);
    }
    sc.close();
  }
}
