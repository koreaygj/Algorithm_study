package Java.baekjoon.gold.BOJ3584;
import java.util.*;

public class Main {
  static int solution(int[] node, int x, int y){
    boolean[] visited = new boolean[10001];
    while(true){
      if(x == 0)
        break;
      visited[x] = true;
      x = node[x];
    }
    while(true){
      if(visited[y])
        return y;
      y = node[y];
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for(int i = 0; i < t; i++){
      int n = sc.nextInt();
      int[] node = new int[10001];
      for(int j = 0; j < n - 1; j++){
        int parent = sc.nextInt();
        int child = sc.nextInt();
        node[child] = parent;
      }
      int x = sc.nextInt();
      int y = sc.nextInt();
      System.out.println(solution(node, x, y));
    }
    sc.close();
  }
}
