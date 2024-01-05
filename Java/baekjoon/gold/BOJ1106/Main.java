package Java.baekjoon.gold.BOJ1106;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] tmp = br.readLine().split(" ");
    int c = Integer.parseInt(tmp[0]);
    int n = Integer.parseInt(tmp[1]);
    int[][] cities = new int[n][2];
    for (int i = 0; i < n; i++) {
      tmp = br.readLine().split(" ");
      cities[i][0] = Integer.parseInt(tmp[0]);
      cities[i][1] = Integer.parseInt(tmp[1]);
    }
    int answer = solution(c, n, cities);
    System.out.println(answer);
  }

  static int solution(int c, int n, int[][] cities) {
    // 드는 비용이 정해졌을때 최대로 늘릴 수 인원수를 찾는 로직
    int[] cost = new int[100001];
    // 최대 비용 c <= 1000 , 도시마다의 최대 비용 = 100
    // 최대 비용 < c * 도시마다의 최대 비용 (100000)
    for (int i = 1; i <= 100000; i++) {
      for (int j = 0; j < n; j++) {
        int prevIndex = i - cities[j][0];
        if (prevIndex < 0)
          continue;
        // 이전의 비용 인덱스가 0보다 크거나 같으면 확인
        // 현재 저장된 값 = cost[i] , 이전 인덱스에서 추가된 인원을 더한 값을 비교 = cost[prevIndex] +
        // cities[j][1];
        cost[i] = Math.max(cost[i], cost[prevIndex] + cities[j][1]);
      }
      // 만약 현재 가격(i)이 동원하고 싶은 인원보다 크거나 같으면 i가 정답
      if (c <= cost[i])
        return i;
    }
    return 0;
  }
}
