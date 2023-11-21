package Java.baekjoon.gold.BOJ2011;

import java.util.*;

public class Main {

  static long solution(String num){
    long[] dp= new long[5001];
    if(num.charAt(0) - '0' == 0)
      return 0;
    dp[0] = 1;
    for(int i = 1; i < num.length(); i++){
      int prev = num.charAt(i - 1) - '0';
      int cur = num.charAt(i) - '0';
      if(1 <= cur && cur <= 9){
        dp[i] = (dp[i] + dp[i - 1]) % 1000000;
      }
      int tmp = prev * 10 + cur;
      if(tmp >= 10 && tmp <= 26){
        if(i == 1){
          dp[i] = dp[i] + 1;
        }
        else{
          dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
      }  
    }
    return dp[num.length() - 1] % 1000000;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String num = sc.nextLine();
    sc.close();
    long answer = solution(num);
    System.out.println(answer);
  }
}
