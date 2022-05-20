import java.util.*;
public class bj2908{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int r_a = 0;
        int r_b = 0;
        for(int i = 2; i >= 0; i--)
        {
            r_a += a % 10 * (int)Math.pow(10, i);
            r_b += b % 10 * (int)Math.pow(10, i);
            a /= 10;
            b /= 10;
        }
        int answer = r_a > r_b ? r_a : r_b;
        System.out.println(answer);
        sc.close();
    }
}