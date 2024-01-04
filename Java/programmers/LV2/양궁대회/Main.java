package Java.programmers.LV2.양궁대회;

import java.util.*;

public class Main {
  static int max_score = -1;
  static int[] lion = new int[11];
  static int[] ans = { -1 };
  public static int cal(int[] info) {
    int a = 0, b = 0;
    for (int i = 0; i < 11; i++) {
      if(lion[i] == 0 && info[i] == 0)
        continue;
      if (lion[i] > info[i])
        a += 10 - i;
      else
        b += 10 - i;
    }
    return a - b;
  }
  public static void dfs(int st, int n, int cnt, int[] info) {
    if (n == 0) {
      int result = cal(info);
      if (result > 0 && max_score <= result) {
        if (max_score == result) {
          for (int i = 10; i >= 0; i--) {
            if(ans[i] > lion[i]){
              return;
            }
            else if (ans[i] < lion[i]) {
              ans = lion.clone();
              return;
            }
          }
        }
        ans = lion.clone();
        max_score = result;
      }
      return;
    }
    for (int i = st; i < 11; i++) {
      if (n < info[i] + 1) {
        lion[i] += 1;
        dfs(i, n - 1, cnt, info);
        lion[i] -= 1;
        continue;
      }
      lion[i] = info[i] + 1;
      dfs(i + 1, n - info[i] - 1, cnt + info[i] + 1, info);
      lion[i] = 0;
    }
  }
  public static int[] solution(int n, int[] info) {
    dfs(0, n, 0, info);
    return ans;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    String str = sc.nextLine();
    String[] s = str.split(",");
    int[] info = new int[11];
    for (int i = 0; i < 11; i++) {
      info[i] = Integer.parseInt(s[i]);
    }
    info = solution(n, info);
    for (int i = 0; i < 11; i++)
      System.out.print(info[i] + ", ");
    System.out.println();
    sc.close();
  }
}
