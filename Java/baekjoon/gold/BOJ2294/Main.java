package Java.baekjoon.gold.BOJ2294;

import java.util.*;


public class Main {

  static int solution(int n, int k, int[]arr){
    int[] dp = new int[100005];
    Arrays.fill(dp, Integer.MAX_VALUE);
    for(int i = 0; i < arr.length; i++){
      if(arr[i] > k)
        continue;
      dp[arr[i]] = 1;
    }

    for(int i = 1; i <= k; i++){
      if(dp[i] != Integer.MAX_VALUE)
        continue;
      for(int coin : arr){
        if(i - coin > 0 && dp[i - coin] != Integer.MAX_VALUE){
          dp[i] = Math.min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    for(int i = 0; i <= k; i++){
      System.out.println(i + ": " + dp[i] + " ");
    }
    return dp[k] == Integer.MAX_VALUE ? -1 : dp[k];
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int[] arr = new int[n];
    for(int i = 0; i < n; i++)
      arr[i] = sc.nextInt();
    sc.close();
    int answer = solution(n, k, arr);
    System.out.println(answer);
  }
}
