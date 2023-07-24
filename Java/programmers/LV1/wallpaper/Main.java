package Java.programmers.LV1.wallpaper;

import java.util.*;

public class Main {
  public static int[] solution(String[] wallpaper) {
    int[] answer = new int[4];
    int[] left = { 55, 55 };
    int[] right = { 0, 0 };
    for (int i = 0; i < wallpaper.length; i++) {
      for (int j = 0; j < wallpaper[i].length(); j++) {
        if (wallpaper[i].charAt(j) == '#') {
          left[0] = Math.min(left[0], i);
          left[1] = Math.min(left[1], j);
          right[0] = Math.max(right[0], i + 1);
          right[1] = Math.max(right[1], j + 1);
        }
      }
    }
    System.arraycopy(left, 0, answer, 0, 2);
    System.arraycopy(right, 0, answer, 2, 2);
    return answer;
}

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String[] str = new String[n];
    sc.nextLine();
    for (int i = 0; i < n; i++) {
      str[i] = sc.nextLine();
    }
    int[] ans = solution(str);
    for (int i = 0; i < ans.length; i++) {
      System.out.print(ans[i] + ", ");
    }
    System.out.println();
    sc.close();
  }
}
