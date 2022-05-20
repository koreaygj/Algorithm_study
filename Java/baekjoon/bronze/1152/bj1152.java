import java.util.*;
public class bj1152{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] answer = input.split(" ");
        if(input.charAt(0) == ' ')
        {
            if(input.length() == 1)
            {
                System.out.println(0);
                return;
            }
            System.out.println(answer.length - 1);
            return;
        }
        System.out.println(answer.length);
        sc.close();
    }
}