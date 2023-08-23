import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        int[] graph = new int[n + 1];
        ArrayList<Integer>[] trunk = new ArrayList[n + 1];
        for(int i = 0; i <= n ;i++)
            trunk[i] = new ArrayList<Integer>();
        for(int i = 0; i < m; i++){ 
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[b]++;
            trunk[a].add(b);
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++){
            if(graph[i] == 0)
                q.add(i);
        }
        while(!q.isEmpty()){
            int st_node = q.poll();
            System.out.print(st_node + " ");
            for(int i = 0; i < trunk[st_node].size(); i++){
                int next_node = trunk[st_node].get(i);
                graph[next_node]--;
                if(graph[next_node] == 0){
                    q.add(next_node);
                }
            }
        }
        sc.close();
    }
}