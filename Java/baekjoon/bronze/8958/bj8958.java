import java.util.*;
public class bj8958{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for(int i = 0;i < t ;i++)
        {
            String str = sc.nextLine();
            int score = 0;
            int answer = 0;
            for(int j = 0; j < str.length(); j++)
            {
                if(str.charAt(j) == 'O')
                    score++;
                else if(str.charAt(j) == 'X')
                    score = 0;
                answer += score;
            }
            System.out.println(answer);
        }
        sc.close();
    }
}