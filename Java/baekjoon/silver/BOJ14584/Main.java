package Java.baekjoon.silver.BOJ14584;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String encodeString = sc.nextLine();
    int n = Integer.parseInt(sc.nextLine());
    String[] words = new String[n];
    for (int i = 0; i < n; i++) {
      words[i] = sc.nextLine();
    }
    sc.close();
    // i칸만큼 옮기기
    for (int i = 0; i < 26; i++) {
      String decodeString = "";
      for (int j = 0; j < encodeString.length(); j++) {
        char c = encodeString.charAt(j);
        decodeString += (char) ((c - 'a' + i) % 26 + 'a');
      }
      // 단어가 해독한 암호에 있는지 확인
      for (int j = 0; j < n; j++) {
        if (decodeString.contains(words[j])) {
          System.out.println(decodeString);
          return;
        }
      }
    }
  }
}
