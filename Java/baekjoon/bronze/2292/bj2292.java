import java.util.*;
public class bj2292{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int answer = 0;
        int cnt = 1;
        while(true)
        {
            cnt = cnt + 6 * answer;
            answer++;
            if(n <= cnt)
                break;
        }
        System.out.println(answer);
        sc.close();
    }
}