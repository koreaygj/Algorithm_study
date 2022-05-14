import java.util.*;

public class bj2525{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        b += c;
        while(b >= 60)
        {
            a += b / 60;
            b %= 60;
        }
        System.out.println(a % 24 + " " + b);
        sc.close();
    }
}