import java.util.*;

public class Main {
  public static int[][] dp;
  public static int solution(int[][] triangle) {
    for (int i = triangle.length - 1; i >= 0; i--) {
      for (int j = 0; j < triangle[i].length - 1; j++) {
        triangle[i - 1][j] += Math.max(triangle[i][j], triangle[i][j + 1]);
      }
    }
    return triangle[0][0];
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    int[][] triangle = new int[n][n];
    for (int i = 0; i < n; i++) {
      String[] s = sc.nextLine().split(",");
      for(int j = 0; j < s.length; j++)
        triangle[i][j] = Integer.parseInt(s[j]);
    }
    System.out.println(solution(triangle));
    sc.close();
  }
}
