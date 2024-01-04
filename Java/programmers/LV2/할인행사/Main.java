package Java.programmers.LV2.할인행사;

import java.util.*;

public class Main {
  public static int solution(String[] want, int[] number, String[] discount) {
    int answer = 0;
    for (int i = 0; i < discount.length - 9; i++) {
      int j;
      for (j = 0; j < want.length; j++) {
        int cnt = 0;
        for (int k = i; k <= i + 10; k++) {
          if (discount[k].equals(want[j]))
            cnt++;
        }
        if (cnt < number[j])
          break;
      }
      if(j == want.length)
        answer++;
    }
    return answer;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    String[] want = new String[n];
    for(int i = 0; i < n; i++)
      want[i] = sc.nextLine();
    int[] number = new int[n];
    for(int i = 0; i < n; i++)
      number[i] = sc.nextInt();
      n = sc.nextInt();
      sc.nextLine();
    String[] discount = new String[n];
    for (int i = 0; i < n; i++) {
      discount[i] = sc.nextLine();
    }
    sc.close();
    System.out.println(solution(want, number, discount));
  }
}
