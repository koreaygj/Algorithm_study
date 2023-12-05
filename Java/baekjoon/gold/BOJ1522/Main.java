package Java.baekjoon.gold.BOJ1522;

import java.util.*;

public class Main {
  static int solution(String st) {
    int cntA = 0;
    int ans = st.length() + 1;
    for (int i = 0; i < st.length(); i++) {
      if (st.charAt(i) == 'a')
        cntA++;
    }
    for (int i = 0; i < st.length(); i++) {
      int tmp = 0;
      for (int j = i; j < i + cntA; j++) {
        if (st.charAt(j % st.length()) == 'b')
          tmp++;
      }
      ans = Math.min(ans, tmp);
    }
    return ans;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    sc.close();
    System.out.println(solution(s));
  }
}
