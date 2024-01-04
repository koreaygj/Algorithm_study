package Java.baekjoon.bronze.BOJ2204;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n;
    while (true) {
      n = Integer.parseInt(br.readLine());
      if (n == 0)
        return;
      String[] word = new String[n];
      String[] lowerCaseWord = new String[n];
      for (int i = 0; i < n; i++) {
        word[i] = br.readLine();
        lowerCaseWord[i] = word[i].toLowerCase();
      }
      Arrays.sort(lowerCaseWord);
      for (int i = 0; i < n; i++) {
        if (word[i].toLowerCase().equals(lowerCaseWord[0])) {
          System.out.println(word[i]);
          break;
        }
      }
    }
  }
}
