package Java.programmers.LV2.sum;
import java.util.*;

public class Main {
  static class Pair {
    int st;
    int end;
    int size;

    public Pair(int st, int end) {
      this.st = st;
      this.end = end;
      this.size = end - st;
    }

    public int compareTo(Pair a){
     if(this.size == a.size) 
       return this.st - a.st;
     return this.size - a.size;
    }
  }
  public static int[] solution(int[] sequence, int k) {
    int[] answer = { 0, sequence.length };
    int left = 0;
    int right = 0;
    int tmp = sequence[0];
    int sz = sequence.length;
    List<Pair> result = new ArrayList<>();
    while (true) {
      if (tmp == k) {
        result.add(new Pair(left, right));
      }
      if (left == sz && right == sz)
        break;
      if (tmp <= k && right < sz) {
        if (++right < sz)
          tmp += sequence[right];
      }
      else {
        if(left < sz)
          tmp -= sequence[left];
        left++;
      }
    }
    result.sort(Pair::compareTo);
    answer[0] = result.get(0).st;
    answer[1] = result.get(0).end;
    return answer;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    String[] tmp = str.split(" ");
    int[] sequence = new int[tmp.length];
    for (int i = 0; i < tmp.length; i++)
      sequence[i] = Integer.parseInt(tmp[i]);
    int k = sc.nextInt();
    int[] ans = solution(sequence, k);
    System.out.println(ans[0] + " " + ans[1]);
    sc.close(); 
  }
}
