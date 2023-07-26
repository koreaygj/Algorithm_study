package Java.programmers.LV2.배열자르기;

import java.util.*;

public class Main {
  public static int[] solution(int n, long left, long right) {
    int[] answer = new int[(int) (right - left + 1)];
    int cnt = 0;
    for (long i = left; i <= right; i++) {
      long a = i % n;
      long b = i / n;
      answer[cnt++] = (int)Math.max(a, b) + 1;
    }
    return answer;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long left = sc.nextLong();
    long right = sc.nextLong();
    int[] ans = solution(n, left, right);
    sc.close();
    for(int i = 0; i < ans.length; i++)
      System.out.print(ans[i] + ", ");
    System.out.println();
  }
}
