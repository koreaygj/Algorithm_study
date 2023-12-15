package Java.baekjoon.gold.BOJ1253;

import java.util.*;

public class Main {
  static int solution(int n, int[] arr) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
      int st = 0;
      int end = n - 1;
      // 판단하려고 하는 숫자
      int curNum = arr[i];
      // 이분 탐색으로 찾기
      while (st < end) {
        // 조건에 부합하는 경우
        if (arr[st] + arr[end] == curNum) {
          // 인덱스에 본인이 있는 지 확인
          if (st != i && end != i) {
            answer++;
            break;
          }
          // 본인이 해당하는 경우
          if (st == i)
            st++;
          else if (end == i)
            end--;
        } else if (arr[st] + arr[end] < curNum) {
          st++;
        } else {
          end--;
        }
      }
    }
    return answer;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();
    sc.close();
    Arrays.sort(arr);
    System.out.println(solution(n, arr));
  }
}
