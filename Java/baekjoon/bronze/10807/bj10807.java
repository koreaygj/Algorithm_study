import java.util.*;

public class bj10807{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        int memo[] = new int[201];
        n = sc.nextInt();
        for(int i = 0; i < n; i++){
            memo[sc.nextInt() + 100]++;
        }
        System.out.println(memo[sc.nextInt() + 100]);
        sc.close();
    }   
}
