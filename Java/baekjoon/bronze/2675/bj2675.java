import java.util.*;
public class bj2675{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < t; i++)
        {
            int r = sc.nextInt();
            String answer = "";
            String input = sc.next();
            for(int j = 0;j < input.length(); j++)
            {
                for(int k = 0;  k < r; k++)
                    answer += input.charAt(j);
            }
            System.out.println(answer);
        }
        sc.close();
    }
}