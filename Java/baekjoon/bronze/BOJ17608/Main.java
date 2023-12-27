package Java.baekjoon.bronze.BOJ17608;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Stack<Integer> v = new Stack<>();
    for (int i = 0; i < n; i++)
      v.push(Integer.parseInt(br.readLine()));
    int answer = 0;
    int tmp = 0;
    while (!v.isEmpty()) {
      int nextStick = v.pop();
      if (tmp < nextStick) {
        answer++;
        tmp = nextStick;
      }
    }
    System.out.println(answer);
  }
}
