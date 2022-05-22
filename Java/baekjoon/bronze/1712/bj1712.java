import java.util.*;
public class bj1712{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        c -= b;
        if(c == 0)
        {
            System.out.println(-1);
            return;
        }
        int answer = a / c + 1;
        if(answer < 0)
        {
            System.out.println(-1);
            return;
        }
        System.out.println(answer);
        sc.close();
    }
}