package Java.baekjoon.gold.BOJ1863;

import java.util.*;

public class Main {
  static int solution(int[][] skyLine) {
    int answer = 0;
    // 이전의 빌딩 확인을 위한 stack
    Stack<Integer> buildings = new Stack<>();
    for (int i = 0; i < skyLine.length; i++) {
      // 빌딩이 없는 구간인 경우 앞에 빌딩들 count
      if (skyLine[i][1] == 0) {
        answer += buildings.size();
        buildings.clear();
        continue;
      }
      // 빌딩이 아무것도 없으면 추가
      if (buildings.empty()) {
        buildings.push(skyLine[i][1]);
        continue;
      }
      // 빌딩이 이전의 높이와 같은 경우 skip
      if (buildings.peek() == skyLine[i][1])
        continue;
      // 이전의 빌딩이 현재의 빌딩보다 큰 경우
      if (buildings.peek() > skyLine[i][1]) {
        // 이전의 빌딩중 현재 빌딩보다 큰 경우만 count후 pop
        while (!buildings.empty() && buildings.peek() > skyLine[i][1]) {
          buildings.pop();
          answer++;
        }
        // 지금 빌딩이 남은 빌딩 보다 높은 경우 || 이전 빌딩이 모두 사라진 경우 빌딩 추가
        if (!buildings.empty() && buildings.peek() < skyLine[i][1])
          buildings.push(skyLine[i][1]);
        if (buildings.empty())
          buildings.push(skyLine[i][1]);
        // 현재 빌딩이 이전의 높이보다 높은 경우
      } else {
        buildings.push(skyLine[i][1]);
      }
    }
    return answer += buildings.size();
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] skyLine = new int[n][2];
    for (int i = 0; i < n; i++) {
      skyLine[i][0] = sc.nextInt();
      skyLine[i][1] = sc.nextInt();
    }
    sc.close();
    System.out.println(solution(skyLine));
  }
}
