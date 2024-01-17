package Java.baekjoon.gold.BOJ1111;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  static int N;
  static int[] Numbers;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    Numbers = new int[N];
    String[] tmp = br.readLine().split(" ");
    for (int i = 0; i < tmp.length; i++) {
      Numbers[i] = Integer.parseInt(tmp[i]);
    }
    System.out.println(findRule(0));
  }

  static String findRule(int stIndex) {
    // 입력이 1인 경우
    if (N == 1)
      return "A";
    int st = Numbers[stIndex];
    int mid = Numbers[stIndex + 1];
    // 입력이 2개인 경우
    if (N == 2) {
      if (st == mid)
        return String.valueOf(st);
      else
        return "A";
    }
    // 입력이 3개 이상인 경우
    int end = Numbers[stIndex + 2];
    if (N >= 3) {
      int a = 0;
      if (st - mid != 0)
        a = (mid - end) / (st - mid);
      int b = mid - st * a;
      int result = checkRule(stIndex + 1, a, b);
      return result != 987654321 ? String.valueOf(result) : "B";
    }
    return "";
  }

  // 찾은 a, b가 다른 숫자에도 동작하면 정답 리턴 아니라면 987654321 리턴
  static int checkRule(int index, int numA, int numB) {
    if (index == N - 1) {
      return Numbers[index] * numA + numB;
    }
    int st = Numbers[index];
    int mid = Numbers[index + 1];
    if (st * numA + numB == mid) {
      return checkRule(index + 1, numA, numB);
    }
    return 987654321;
  }
}
