import java.util.*;
public class bj24416{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(fibonacci_A(n) + " " + (n - 2));
        sc.close();
    }
    public static int fibonacci_A(int n){
        if(n == 1 || n == 2)
        return 1;
        return fibonacci_A(n - 1) + fibonacci_A(n - 2);
    }
}