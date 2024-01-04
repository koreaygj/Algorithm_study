package Java.baekjoon.silver.BOJ1049;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] tmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    int n = tmp[0];
    int m = tmp[1];
    int minSixStrings = 1001;
    int minString = 1001;
    for (int i = 0; i < m; i++) {
      tmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
      minSixStrings = Math.min(tmp[0], minSixStrings);
      minString = Math.min(tmp[1], minString);
    }
    br.close();
    int answer = Math.min((n / 6 + 1) * minSixStrings, (n / 6) * minSixStrings + (n % 6) * minString);
    if (minSixStrings > minString * 6)
      answer = Math.min(answer, minString * n);
    System.out.println(answer);a
  }
}