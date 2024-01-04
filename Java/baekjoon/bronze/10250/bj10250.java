import java.util.*;
public class bj10250{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[] ans = new int[t];
        for(int i = 0; i < t; i++)
        {
            int answer = 0;
            int h = sc.nextInt();
            sc.nextInt();
            int n = sc.nextInt();
            answer = n % h * 100;
            if(n % h == 0){
                answer += h * 100;
                answer += n / h;
            }
            else
                answer += n / h + 1;
            ans[i] = answer;
        }
        for(int i = 0; i < t; i++)
            System.out.println(ans[i]);
        sc.close();
    }
}