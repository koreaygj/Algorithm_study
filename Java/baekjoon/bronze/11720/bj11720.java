import java.util.*;
public class bj11720{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String num = sc.nextLine();
        int answer = 0;
        for(int i = 0; i < num.length(); i++)
        {
            answer += num.charAt(i) - '0';
        }
        System.out.println(answer);
    }
}