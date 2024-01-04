import java.util.*;

public class bj2480{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int answer = 0;
        if(a == b && b == c)
        {
            answer = 10000 + a * 1000;
        }
        else if(a == b || b == c)
            answer = 1000 + b * 100;
        else if(a == c)
            answer = 1000 + a * 100;
        else 
            answer = Math.max(a, Math.max(c, b)) * 100;
        System.out.println(answer);
        sc.close();
    }
}