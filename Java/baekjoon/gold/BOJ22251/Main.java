package Java.baekjoon.gold.BOJ22251;

import java.util.*;

public class Main {
  static int solution(int n, int k, int p, int x) {
    int result = 0;
    int[][] led = {
        { 1, 1, 1, 1, 1, 1, 0 }, // 0
        { 0, 1, 1, 0, 0, 0, 0 }, // 1
        { 1, 1, 0, 1, 1, 0, 1 }, // 2
        { 1, 1, 1, 1, 0, 0, 1 }, // 3
        { 0, 1, 1, 0, 0, 1, 1 }, // 4
        { 1, 0, 1, 1, 0, 1, 1 }, // 5
        { 1, 0, 1, 1, 1, 1, 1 }, // 6
        { 1, 1, 1, 0, 0, 0, 0 }, // 7
        { 1, 1, 1, 1, 1, 1, 1 }, // 8
        { 1, 1, 1, 1, 0, 1, 1 } // 9
    };
    String curFloor = String.valueOf(x);
    while (curFloor.length() < k) {
      curFloor = "0" + curFloor;
    }
    for (int i = 1; i <= n; i++) {
      // 같은 층 제외
      if (i == x)
        continue;
      String villainFloor = String.valueOf(i);
      while (villainFloor.length() < k) {
        villainFloor = "0" + villainFloor;
      }
      int cnt = 0;
      // 자릿수 크기 만큼 반복
      for (int j = 0; j < curFloor.length(); j++) {
        // 자릿수 마다의 LED
        int[] curFloorLed = led[curFloor.charAt(j) - '0'];
        int[] villainFloorLed = led[villainFloor.charAt(j) - '0'];
        for (int m = 0; m < 7; m++) {
          if (curFloorLed[m] != villainFloorLed[m])
            cnt++;
        }
      }
      // 모든 자릿수 돌았을때 바뀐 값이 P보다 작으면 cnt
      if (cnt <= p) {
        result++;
      }
    }
    return result;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int p = sc.nextInt();
    int x = sc.nextInt();
    sc.close();
    int answer = solution(n, k, p, x);
    System.out.println(answer);
  }
}