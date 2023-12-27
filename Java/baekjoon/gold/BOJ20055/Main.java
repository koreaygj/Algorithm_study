package Java.baekjoon.gold.BOJ20055;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
  static void solution(int n, int k, ArrayList<Integer> conveyorBelt) {
    int count = 0;
    int progress = 0;
    ArrayList<Integer> robots = new ArrayList<>();
    for (int i = 0; i < n; i++)
      robots.add(0);
    int endIndex = 2 * n - 1;
    while (k > count) {
      // 벨트가 움직임
      conveyorBelt.add(0, conveyorBelt.remove(endIndex));
      // 도착점 로봇 없애기
      robots.remove(n - 1);
      robots.add(0, 0);
      robots.set(n - 1, 0);

      // 로봇이 움직임 (0 ~ n까지 존재 가능)
      for (int i = n - 2; i >= 0; i--) {
        if (robots.get(i) != 0 && robots.get(i + 1) == 0 && conveyorBelt.get(i + 1) > 0) {
          robots.set(i, 0);
          conveyorBelt.set(i + 1, conveyorBelt.get(i + 1) - 1);
          robots.set(i + 1, 1);
          count += conveyorBelt.get(i + 1) == 0 ? 1 : 0;
        }
      }
      // 컨베이어 벨트 수명만 남아있으면 추가
      if (conveyorBelt.get(0) > 0) {
        robots.set(0, 1);
        conveyorBelt.set(0, conveyorBelt.get(0) - 1);
        count += conveyorBelt.get(0) == 0 ? 1 : 0;
      }
      progress++;
    }
    System.out.println(progress);
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] tmp = br.readLine().split(" ");
    int n = Integer.parseInt(tmp[0]);
    int k = Integer.parseInt(tmp[1]);
    int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    ArrayList<Integer> conveyorBelt = new ArrayList<>();
    for (int i = 0; i < arr.length; i++)
      conveyorBelt.add(arr[i]);
    solution(n, k, conveyorBelt);
  }
}
