package Java.baekjoon.gold.BOJ1027;

import java.util.*;

public class Main {
  static int countBuilding(int n, int target, int[] arr) {
    int cnt = 0;
    double gradRight = Integer.MAX_VALUE * -1;
    double gradLeft = Integer.MAX_VALUE;
    // 타겟의 오른쪽
    for (int i = target + 1; i < n; i++) {
      double tmp = (arr[i] - arr[target]) / (1.0d * (i - target));
      if (tmp > gradRight) {
        cnt++;
        gradRight = tmp;
      }
    }
    // 타겟의 왼쪽
    for (int i = target - 1; i >= 0; i--) {
      double tmp = (arr[i] - arr[target]) / (1.0d * (i - target));
      if (tmp < gradLeft) {
        cnt++;
        gradLeft = tmp;
      }
    }
    return cnt;
  }

  static int solution(int n, int[] arr) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
      answer = Math.max(countBuilding(n, i, arr), answer);
    }
    return answer;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();
    sc.close();
    System.out.println(solution(n, arr));
    LinkedList<Integer, Integer> r = new LinkedList<>();
    r.toList();
  }
}
