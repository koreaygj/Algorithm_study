package Java.baekjoon.silver.BOJ20922;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
  static int solution(int n, int k, int[] arr) {
    int result = 0;
    int st = 0;
    int end = 0;
    // 수열에 존재하는 숫자 세는 HashMap
    HashMap<Integer, Integer> count = new HashMap<>();
    while (end < n) {
      // 수열에 k개 이상인 숫자가 존재하는 경우
      if (count.getOrDefault(arr[end], 0) >= k) {
        count.put(arr[st], count.get(arr[st]) - 1);
        result = Math.max(end - st, result);
        st++;
      } else { // 수열에 k개 이상인 숫자가 없을 때
        count.put(arr[end], count.getOrDefault(arr[end], 0) + 1);
        end++;
      }
    }
    result = Math.max(end - st, result);
    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());

    int[] arr = new int[n];
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }
    int answer = solution(n, k, arr);
    System.out.println(answer);
  }
}
