import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      int n = sc.nextInt();
      int[] sum = new int[n + 1];
      if (n == 0)
        break;
      for (int i = 0; i < n; i++) {
        int p = sc.nextInt();
        sum[i + 1] = sum[i] + p > p ? sum[i + 1] = sum[i] + p : p;
      }
      int maxSum = Integer.MIN_VALUE;
      for (int i = 1; i <= n; i++) {
        maxSum = maxSum < sum[i] ? sum[i] : maxSum;
      }
      System.out.println(maxSum);
    }
    sc.close();
  }
}