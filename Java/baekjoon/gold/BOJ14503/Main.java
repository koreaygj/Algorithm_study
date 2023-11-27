import java.util.*;
public class Main {
  static class Point{
    int x;
    int y;
    int direction;
    public Point(int x, int y, int d){
      this.x = x;
      this.y = y;
      this.direction = d;
    }
  }
  static int N;
  static int M;
  static int[][] Map = new int[51][51];
  static int bfs(Point st){
    System.out.println(st.x + " " + st.y);
    Map[st.x][st.y] = 2;
    int[] nextX = {-1, 0, 1, 0};
    int[] nextY = {0, -1, 0, 1};
    for(int i = 1; i < 5; i++){
      int nextDirection = (st.direction + i) % 4;
      System.out.println(nextDirection);
      Point next = new Point(st.x + nextX[nextDirection] , st.y + nextY[nextDirection], nextDirection);
      if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
        continue;
      if(Map[next.x][next.y] != 0)
        continue;
      return bfs(next) + 1;
    }
    Point back = new Point(st.x - nextX[st.direction], st.y - nextY[st.direction], st.direction);
    if(back.x < 0 || back.x >= N || back.y < 0 || back.y >= M || Map[back.x][back.y] == 1)
      return 1;
    else
      return bfs(back);
  }
  static int solution(int r, int c, int d){
    if(Map[r][c] != 0)
      return 0;
    if(d == 3)
      d = 1;
    else if(d == 1)
      d = 3;
    Point st = new Point(r, c, d);
    return bfs(st);
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    int r = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        Map[i][j] = sc.nextInt();
      }
    }
    sc.close();
    System.out.println(solution(r, c, d));
  }
}
