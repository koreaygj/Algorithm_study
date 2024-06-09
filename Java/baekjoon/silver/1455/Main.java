import java.io.*;

public class Main {
  static int board[][] = new int[101][101];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String input[] = br.readLine().split(" ");
    int n = Integer.parseInt(input[0]);
    int m = Integer.parseInt(input[1]);
    for (int i = 0; i < n; i++) {
      String boardInput = br.readLine();
      for (int j = 0; j < m; j++) {
        board[i][j] = boardInput.charAt(j) - '0';
      }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (board[i][j] == 1) {
          coinFlip(i, j);
          ans++;
        }
      }
    }
    bw.write(ans + "\n");
    br.close();
    bw.close();
  }

  static void coinFlip(int x, int y) {
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= y; j++) {
        board[i][j] = board[i][j] == 0 ? 1 : 0;
      }
    }
  }
}
