import java.util.Scanner;

public class Main {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String input[] = sc.nextLine().split(" ");
    String king = input[0];
    int kingRow = Integer.parseInt(king.substring(1)) - 1;
    int kingColumn = (int) (king.charAt(0) - 'A');
    String stone = input[1];
    int stoneRow = Integer.parseInt(stone.substring(1)) - 1;
    int stoneColumn = (int) (stone.charAt(0) - 'A');
    int n = Integer.parseInt(input[2]);
    String[] move = new String[n];
    for (int i = 0; i < n; i++)
      move[i] = sc.next();
    sc.close();
    moveKing(kingRow, kingColumn, stoneRow, stoneColumn, 0, move);
    return;
  }

  public static void moveKing(int kingRow, int kingColumn, int stoneRow, int stoneColumn, int cnt, String[] move) {
    if (cnt == move.length) {
      String king = (char) ('A' + kingColumn) + Integer.toString(kingRow + 1);
      String stone = (char) ('A' + stoneColumn) + Integer.toString(stoneRow + 1);
      System.out.println(king);
      System.out.println(stone);
      return;
    }
    if (move[cnt].equals("R")) {
      if (kingColumn + 1 >= 8) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn + 1 == stoneColumn && kingRow == stoneRow) {
          if (stoneColumn + 1 >= 8) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow, kingColumn + 1, stoneRow, stoneColumn + 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow, kingColumn + 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("L")) {
      if (kingColumn - 1 < 0) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn - 1 == stoneColumn && kingRow == stoneRow) {
          if (stoneColumn - 1 < 0) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow, kingColumn - 1, stoneRow, stoneColumn - 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow, kingColumn - 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("B")) {
      if (kingRow - 1 < 0) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn == stoneColumn && kingRow - 1 == stoneRow) {
          if (stoneRow - 1 < 0) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow - 1, kingColumn, stoneRow - 1, stoneColumn, cnt + 1, move);
          }
        } else {
          moveKing(kingRow - 1, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("T")) {
      if (kingRow + 1 >= 8) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn == stoneColumn && kingRow + 1 == stoneRow) {
          if (stoneRow + 1 >= 8) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow + 1, kingColumn, stoneRow + 1, stoneColumn, cnt + 1, move);
          }
        } else {
          moveKing(kingRow + 1, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("RT")) {
      if (kingRow + 1 >= 8 || kingColumn + 1 >= 8) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn + 1 == stoneColumn && kingRow + 1 == stoneRow) {
          if (stoneRow + 1 >= 8 || stoneColumn + 1 >= 8) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow + 1, kingColumn + 1, stoneRow + 1, stoneColumn + 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow + 1, kingColumn + 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("LT")) {
      if (kingRow + 1 >= 8 || kingColumn - 1 < 0) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn - 1 == stoneColumn && kingRow + 1 == stoneRow) {
          if (stoneRow + 1 >= 8 || stoneColumn - 1 < 0) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow + 1, kingColumn - 1, stoneRow + 1, stoneColumn - 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow + 1, kingColumn - 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("RB")) {
      if (kingRow - 1 < 0 || kingColumn + 1 >= 8) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn + 1 == stoneColumn && kingRow - 1 == stoneRow) {
          if (stoneRow - 1 < 0 || stoneColumn + 1 >= 8) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow - 1, kingColumn + 1, stoneRow - 1, stoneColumn + 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow - 1, kingColumn + 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    } else if (move[cnt].equals("LB")) {
      if (kingRow - 1 < 0 || kingColumn - 1 < 0) {
        moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
      } else {
        if (kingColumn - 1 == stoneColumn && kingRow - 1 == stoneRow) {
          if (stoneRow - 1 < 0 || stoneColumn - 1 < 0) {
            moveKing(kingRow, kingColumn, stoneRow, stoneColumn, cnt + 1, move);
          } else {
            moveKing(kingRow - 1, kingColumn - 1, stoneRow - 1, stoneColumn - 1, cnt + 1, move);
          }
        } else {
          moveKing(kingRow + -1, kingColumn - 1, stoneRow, stoneColumn, cnt + 1, move);
        }
      }
    }
  }

}