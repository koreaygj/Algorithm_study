import java.util.*;
public class bj1193{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        sc.close();
        int answer = 0;
        int cnt = 0;
        while(true)
        {
            cnt++;
            answer++;
            if(x - cnt <= 0)
                break;
            x -= cnt;
        }
        if(answer % 2 == 0)
        {
        answer = answer + 1 - x;
        System.out.println(x + "/" + answer);
        return;
        }
        answer++;
        System.out.println(answer - x + "/" + x);
    }
}