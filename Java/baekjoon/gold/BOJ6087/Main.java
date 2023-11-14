package Java.baekjoon.gold.BOJ6087;
import java.util.*;

public class Main {

  //point 객체
  public static class Point {
    //x, y 좌표, prePathIndex: 이 점에 도달하기 위해 움직인 방향, cnt: 이 점에 도달하기 까지 사용된 거울의수
    int x;
    int y;
    int prevPathIndex;
    int cnt;
    public Point(int x, int y){
      this.x = x;
      this.y = y;
      this.prevPathIndex = -1;
      this.cnt = 0;
    }
    // Point 객체 움직임 메서드
    public Point move(int i){
      int moveX[] = {-1, 0, 1, 0};
      int moveY[] = {0, 1, 0, -1};
      int x = this.x + moveX[i];
      int y = this.y + moveY[i];
      return new Point(x, y);
    }
  };

  static int solution(int h, int w, char[][] map, Point stPoint, Point endPoint){
    int answer = Integer.MAX_VALUE;
    Queue<Point> q = new LinkedList<>();

    // 각 점에 도달하는 방향에 따른 최솟값을 저장하기 위한 배열
    int[][][] visited = new int[101][101][4];

    // 배열 Integer 최댓값으로 초기화
    for(int i = 0; i < 101; i++){
      for(int j = 0; j < 101; j++)
        for(int k = 0; k < 4; k++)
          visited[i][j][k] = Integer.MAX_VALUE;
    }

    // 시작점 queue에 대입
    q.add(stPoint);

    // 모든 방향에 대한 시작점 visited 1로 초기화
    for(int i = 0; i < 4; i++)
      visited[stPoint.x][stPoint.y][i] = 1;

    while(!q.isEmpty()){
      // 현재 위치 cur
      Point cur = q.poll();

      // cur 와 도착점이 같은 경우 visited에서 최솟값 가져오기
      if(cur.x == endPoint.x && cur.y == endPoint.y){
        for(int i = 0; i < 4; i++)
          answer = Math.min(answer, visited[cur.x][cur.y][i]);
        continue;
      }

      // cur에서 4가지 방향으로 움직여보기
      for(int i = 0; i < 4; i++){
        Point next = cur.move(i);

        // map을 벗어나는 경우 continue;
        if(next.x < 0 || next.x >= h || next.y < 0 || next.y >= w || map[next.x][next.y] == '*')
        continue;

        // map을 벗어나지 않는 경우 왔던 방향과 다를 때 cur.cnt + 1을 next.cnt에 저장
        next.cnt = (cur.prevPathIndex != i && cur.prevPathIndex != -1 )? cur.cnt + 1 : cur.cnt;

        // next에 도달한 방향으로 이전에 방문한 경우가 거울 수가 적으면 continue;
        if(visited[next.x][next.y][i] <= next.cnt)
          continue;

        // 아닌경우 visited 갱신, next 객체 queue에 넣기
        next.prevPathIndex = i;
        visited[next.x][next.y][i] = next.cnt;
        q.add(next);
      }
    }
    return answer;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char[][] map = new char[101][101];
    // 입력 받기
    int w = sc.nextInt();
    int h = sc.nextInt();
    sc.nextLine();
    Point stPoint = new Point(-1, -1);
    Point endPoint = new Point(-1, -1);
    int cnt = 0;
    for(int i = 0; i < h; i++){
      String tmp = sc.nextLine();
      for(int j = 0; j < w; j++){
        map[i][j] = tmp.charAt(j);
        if(map[i][j] == 'C'){
          if(cnt == 0){
            stPoint = new Point(i, j);
            cnt++;
          }
          else{
            endPoint = new Point(i, j);
          }
        }
      }
    }
    sc.close();
    int ans = solution(h, w, map, stPoint, endPoint);
    System.out.println(ans);
  }
}