import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            int find_m = i;
            int sum = 0;
            while(find_m != 0)
            {
                sum += find_m % 10;
                find_m /= 10;
            }
            if(sum + i == n)
            {
                answer = i;
                break;
            }
        }
        System.out.println(answer);
        sc.close();
    }
}