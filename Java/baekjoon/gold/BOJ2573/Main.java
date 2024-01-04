import java.util.*;

class Point{
    int x;
    int y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    public Point move(int i){
        int moveX[] = {-1, 0, 1, 0};
        int moveY[] = {0, 1, 0, -1};  
        int x = this.x + moveX[i];
        int y = this.y + moveY[i];
        return new Point(x, y);
    }
};

public class Main {
    static int N;
    static int M;
    static int Map[][];
    
    static void meltIce(){
        Queue<Point> q = new LinkedList<>();
        boolean visited[][] = new boolean[301][301];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] > 0){
                    q.add(new Point(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while(!q.isEmpty()){
            Point cur = q.poll();
            int sea = 0;
            for(int i = 0; i < 4; i++){
                Point next = cur.move(i);
                if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
                    continue;
                if(!visited[next.x][next.y] && Map[next.x][next.y] == 0)
                    sea++;
            }
            if(Map[cur.x][cur.y] - sea < 0)
                Map[cur.x][cur.y] = 0;
            else
                Map[cur.x][cur.y] -= sea;
        }
    }
    
    static void dfs(Point st, boolean visited[][]){
        
        visited[st.x][st.y] = true;
        
        for(int i = 0; i < 4; i++){
            Point next = st.move(i);
            if(!visited[next.x][next.y] && Map[next.x][next.y] != 0)
                dfs(next, visited);
        }
        
    }
    
    static int countIce(){
        boolean visited[][] = new boolean[301][301];
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] != 0 && !visited[i][j]){
                    dfs(new Point(i, j), visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }


    static int solution(){
        int answer = 0;
        while(true){
            int iceBerg = countIce();
            if(iceBerg > 1)
                return answer;
            if(iceBerg == 0)
                return 0;
            answer++;
            meltIce();
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Map = new int[301][301];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                Map[i][j] = sc.nextInt();
            }
        }
        sc.close();

        System.out.println(solution());
    }
}
