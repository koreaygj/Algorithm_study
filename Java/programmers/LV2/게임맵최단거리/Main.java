import java.util.*;
public class Main {
    static class pair{
        int x;
        int y;
        int cnt;
        public pair(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
        public boolean comp(pair a){
            if(this.x == a.x && this.y == a.y)
                return true;
            return false;
        }
    }
    static int bfs(int[][] maps){
        int[][] move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int n = maps.length;
        int m = maps[0].length;
        boolean visited[][] = new boolean[n][m];
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(0, 0, 0));
        visited[0][0] = true;
        while(!q.isEmpty()){
            pair cur = q.poll();
            if(cur.comp(new pair(n - 1, m - 1, 0)))
                return cur.cnt + 1;
            q.remove(cur);
            for(int i = 0; i < 4; i++){
                pair next = new pair(cur.x + move[i][0], cur.y + move[i][1], cur.cnt + 1);
                if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
                    continue;
                if(visited[next.x][next.y] || maps[next.x][next.y] == 0)
                    continue;
                visited[next.x][next.y] = true;
                q.add(next);
            }
        }
        return -1;
    }
    public static int solution(int[][] maps){
        return bfs(maps);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        int[][] maps = new int[n][m];
        for(int i = 0; i < n; i++){
            String[] tmp = sc.nextLine().split(",");
            for(int j = 0; j < m; j++)
                maps[i][j] = Integer.parseInt(tmp[j]);
        }
        System.out.println(solution(maps));
        sc.close();
    }
}
