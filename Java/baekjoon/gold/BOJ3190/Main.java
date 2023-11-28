import java.util.*;
public class Main{
  static boolean checkEnd(int x, int y, int n, LinkedList<int[]> snake){
    if(x <= 0 || x > n || y <= 0 ||  y > n)
      return true;
    for(int i = 0; i < snake.size(); i++){
      int[] tmp = snake.get(i);
      if(tmp[0] == x && tmp[1] == y)
        return true;
    }
    return false;
  }
  static int solution(int n, int[][] map, String[] direction){
    int[] moveX = {0, 1, 0, -1};
    int[] moveY = {1, 0, -1, 0};
    int time = 0;
    int curX = 1;
    int curY = 1;
    LinkedList<int[]> snake = new LinkedList<>();
    snake.add(new int[] {1, 1});
    int d = 0;
    while(true){
      time++;
      int nextX = curX + moveX[d];
      int nextY = curY + moveY[d];
      if(checkEnd(nextX, nextY, n, snake))
        return time;
      if(map[nextX][nextY] == 1){
        map[nextX][nextY] = 0;
      }
      else{
        snake.remove(0);
      }
      snake.add(new int[] {nextX, nextY});
      curX = nextX;
      curY = nextY;
      if(direction[time] != null){
        d = direction[time].equals("D") ? (d + 1) % 4 : (d - 1) % 4;
        if(d < 0)
          d = 3;
      }
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int[][] map = new int[101][101];
    for(int i = 0; i < k; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      map[a][b] = 1;
    }
    int l = sc.nextInt();
    String[] direction = new String[10003];
    for(int i = 0; i < l; i++){
      int a = sc.nextInt();
      String b = sc.next();
      direction[a] = b;
    }
    sc.close();
    System.out.println(solution(n, map, direction));
  }
}