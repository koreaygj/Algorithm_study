import java.util.*;

public class Main {
  private static class Point{
    public final long x, y;

    public Point(long x, long y) {
      this.x = x;
      this.y = y;
    }
  }
  
  public static String[] solution(int[][] line) {
    List<Point> dots = new ArrayList<>();
    Long left = Long.MAX_VALUE;
    Long right = Long.MIN_VALUE;
    Long top = Long.MIN_VALUE;
    Long bottom = Long.MAX_VALUE;
    for (int i = 0; i < line.length - 1; i++) {
      for (int j = i + 1; j < line.length; j++) {
        Long x_up = (long)line[i][1] * (long)line[j][2] - (long)line[i][2] * (long)line[j][1];
        Long x_down = (long)line[i][0] * (long)line[j][1] - (long)line[i][1] * (long)line[j][0];
        Long y_up = (long)line[i][2] * (long)line[j][0] - (long)line[i][0] * (long)line[j][2];
        if (x_down == 0)
          continue;
        double x = x_up / (double) x_down;
        double y = y_up / (double) x_down;
        if (x % 1 != 0 || y % 1 != 0)
          continue;
        left = Math.min((long)x, left);
        right = Math.max((long)x, right);
        top = Math.max((long)y, top);
        bottom = Math.min((long)y, bottom);
        dots.add(new Point((long)x, (long)y));
      }
    }
    int height = (int)(top - bottom + 1);
    int wide = (int)(right - left + 1);
    boolean board[][] = new boolean[height][wide];
    String[] answer = new String[height];
    for (int i = 0; i < dots.size(); i++) {
      board[(int)(dots.get(i).y - bottom)][(int)(dots.get(i).x - left)] = true;
    }
    for (int i = height - 1; i >= 0; i--) {
      String tmp = "";
      for (int j = 0; j < wide; j++) {
        if (board[i][j])
          tmp += "*";
        else
          tmp += ".";
      }
      answer[height - i - 1] = tmp;
    }
    return answer;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int line[][] = new int[n][3];
    for (int i = 0; i < n; i++) {
      line[i][0] = sc.nextInt();
      line[i][1] = sc.nextInt();
      line[i][2] = sc.nextInt();
    }
    String[] ans = solution(line);
    for (int i = 0; i < ans.length; i++){
      System.out.println(ans[i]);
    }
    sc.close();
  }
}
