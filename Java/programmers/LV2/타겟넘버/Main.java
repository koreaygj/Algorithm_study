package Java.programmers.LV2.타겟넘버;

import java.util.*;

public class Main {
  static int[] pos;
  static int ans = 0;
  static boolean check(int[] numbers, int target) {
    int result = 0;
    for (int i = 0; i < numbers.length; i++) {
      result += pos[i] * numbers[i];
    }
    return result == target;
  }
  static void dfs(int cnt, int[] numbers, int target){
    if (cnt == numbers.length) {
      for (int i = 0; i < numbers.length; i++)
        System.out.print(pos[i] + ", ");
      System.out.println();
      if(check(numbers, target))
        ans++;
      return;
    }
    pos[cnt] = 1;
    dfs(cnt + 1, numbers, target);
    pos[cnt] = -1;
    dfs(cnt + 1, numbers, target);
  }
  public static int solution(int[] numbers, int target) {
    pos = new int[numbers.length];
    dfs(0, numbers, target);
    return ans;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(", ");
    int target = sc.nextInt();
    int numbers[] = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      numbers[i] = Integer.parseInt(s[i]);
    }
    solution(numbers, target);
    sc.close();
  }
}
