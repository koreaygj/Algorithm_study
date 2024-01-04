import java.util.*;
class Solution {
    public int solution(int x, int y, int n) {
        int answer = -1;
        int memo[] = new int[1000001];
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        while(!q.isEmpty()){
            int cur = q.element();
            q.remove();
            if(cur == y){
                answer = memo[cur];
                break;
                
            }
            int next[] = {cur + n , cur * 2, cur * 3};
            for(int nx : next){
                if(nx > y || memo[nx] != 0)
                    continue;
                memo[nx] = memo[cur] + 1;
                q.add(nx);
            }
        }
        return answer;
    }
}