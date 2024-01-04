package Java.baekjoon.gold.BOJ1759;

import java.util.*;

public class Main {
  static class Password {
    String pw;
    int index;

    public Password(String pw, int index) {
      this.pw = pw;
      this.index = index;
    }
  }

  static void solution(int l, int c, String[] arr) {
    // 결과를 저장할 list
    List<String> answer = new ArrayList<>();
    Arrays.sort(arr);
    // queue
    Queue<Password> q = new LinkedList<>();
    // 시작할 문자 큐에 추가
    for (int i = 0; i <= c - l; i++)
      q.add(new Password(arr[i], i));
    while (!q.isEmpty()) {
      Password cur = q.poll();
      // 선택한 문자보다 사전순으로 뒤에 있는 문자열 추가
      for (int i = cur.index + 1; i < c; i++) {
        Password next = new Password(cur.pw + arr[i], i);
        // 만들어진 문자열의 길이가 l과 같으면 결과에 저장
        if (next.pw.length() == l) {
          answer.add(next.pw);
          continue;
        }
        q.add(next);
      }
    }
    for (String result : answer) {
      // 모음이 1개이상 자음이 2개이상인지 확인후 출력
      if (isPossible(result))
        System.out.println(result);
    }
  }

  static boolean isPossible(String pw) {
    char[] gather = { 'a', 'e', 'i', 'o', 'u' };
    boolean isGather = false;
    int cntGather = 0;
    int cntConsonant = 0;
    // 문자열에 모음개수 자음개수 세기
    for (int i = 0; i < pw.length(); i++) {
      isGather = false;
      for (int j = 0; j < gather.length; j++) {
        if (pw.charAt(i) == gather[j]) {
          isGather = true;
          break;
        }
      }
      if (isGather)
        cntGather++;
      else
        cntConsonant++;
    }
    // 조건에 부함하면 true 아니면 false
    return cntGather >= 1 && cntConsonant >= 2;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int l = sc.nextInt();
    int c = sc.nextInt();
    String[] arr = new String[c];
    for (int i = 0; i < c; i++)
      arr[i] = sc.next();
    sc.close();
    solution(l, c, arr);
  }
}