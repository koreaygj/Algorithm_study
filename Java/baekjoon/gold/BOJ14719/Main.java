package Java.baekjoon.gold.BOJ14719;

import java.util.*;

public class Main {
  static int solution(int h, int w, int[] map) {
    int answer = 0;
    for (int i = 1; i < w; i++) {
      int leftLevel = 0;
      int rightLevel = 0;
      // 왼쪽 벽
      for (int j = 0; j < i; j++)
        leftLevel = Math.max(map[j], leftLevel);
      // 오른쪽 벽
      for (int j = i + 1; j < w; j++)
        rightLevel = Math.max(map[j], rightLevel);
      // 고인물 양 추가
      if (leftLevel > map[i] && rightLevel > map[i])
        answer += Math.min(leftLevel, rightLevel) - map[i];
    }
    return answer;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int[] map = new int[w + 1];
    for (int i = 0; i < w; i++)
      map[i] = sc.nextInt();
    sc.close();
    System.out.println(solution(h, w, map));
  }
}
