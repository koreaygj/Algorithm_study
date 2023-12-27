package Java.baekjoon.silver.BOJ15810;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  static void solution(int n, int m, long[] staff) {
    long left = 0;
    long right = m * staff[0];
    while (left + 1 < right) {
      long mid = (left + right) / 2;
      long tmp = 0;
      for (int i = 0; i < staff.length; i++)
        tmp += mid / staff[i];
      if (tmp >= m)
        right = mid;
      else
        left = mid;
    }
    System.out.println(right);
    return;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] tmp = br.readLine().split(" ");
    int n = Integer.parseInt(tmp[0]);
    int m = Integer.parseInt(tmp[1]);
    long[] staff = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
    Arrays.sort(staff);
    solution(n, m, staff);
  }
}
