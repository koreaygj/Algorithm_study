package Java.baekjoon.gold.BOJ2631;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] input = new int[n];
    for(int i = 0; i < n; i++) input[i] = sc.nextInt();
    sc.close();
    int[] dp = new int[n];
    dp[0] = 1;

    int ans = 0;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(input[i] > input[j]) 
              dp[i] = Math.max(dp[i], dp[j]+1);
        }
        ans = Math.max(ans, dp[i]);
    }
    System.out.println(n - ans);
  }
}
