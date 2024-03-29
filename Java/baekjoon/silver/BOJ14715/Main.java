package Java.baekjoon.silver.BOJ14715;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/*
  슬라임 1 -> 2마리
  흠집 T -> T + 1 2마리
  K = A * B
  마지막 슬라임은 모두 소수
*/
public class Main {
  static int solution(int n) {
    int cnt = 0;
    int tmp = n;
    // 소인수 분해의 개수
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        while (tmp % i == 0) {
          cnt++;
          tmp /= i;
        }
      }
    }
    // 소인수분해 값들로 완전이진트리를 만들었을 때 트리 높이가 정답
    return cnt == 0 ? 0 : (int) Math.ceil(Math.log(cnt) / Math.log(2));
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    System.out.println(solution(n));
  }
}