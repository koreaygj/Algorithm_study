import java.util.*;
public class bj2839{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int f_kg = n / 5;
        int t_kg = 0;
        n %= 5;
        Boolean check = false;
        for(int i = f_kg; i >= 0; i--)
        {
            if(n % 3 == 0)
            {
                f_kg = i;
                t_kg = n / 3;
                check = true;
                break;
            }
            n += 5;
        }
        if(check == false)
        {
            System.out.println(-1);
            return;
        }
        System.out.println(f_kg + t_kg);
        sc.close();
    }
}