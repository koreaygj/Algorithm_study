import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String input = br.readLine();
    int n = Integer.parseInt(input);
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    for (int i = 0; i < n; i++) {
      input = br.readLine();
      String num[] = input.split(" ");
      for (int j = 0; j < num.length; j++) {
        int cur = Integer.parseInt(num[j]);
        pq.offer(cur);
        if (pq.size() > n) {
          pq.poll();
        }
      }
    }
    bw.write((pq.peek() + "\n"));
    br.close();
    bw.close();
  }
}
