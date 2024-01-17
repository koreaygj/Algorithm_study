package Java.baekjoon.silver.BOJ14916;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int changes = sc.nextInt();
    sc.close();
    int answer = 0;
    int[] dp = new int[100001];
    // 최댓값으로 채우기
    Arrays.fill(dp, 100000);
    // 초기 2원 5원 최소값 1로 변경
    dp[2] = 1;
    dp[5] = 1;
    for (int i = 1; i <= changes; i++) {
      if (i - 2 > 0) {
        dp[i] = Math.min(dp[i], dp[i - 2] + 1);
      }
      if (i - 5 > 0) {
        dp[i] = Math.min(dp[i], dp[i - 5] + 1);
      }
    }
    answer = dp[changes] == 100000 ? -1 : dp[changes];
    System.out.println(answer);
  }
}
