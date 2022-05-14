import java.util.*;

public class bj1110
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n < 10)
            n *= 10;
        int answer = 0;
        int st_num = n;
        while(true)
        {
            int ten_digit = st_num % 10;
            int num_digit = st_num / 10 + ten_digit;
            if(num_digit >= 10)
                num_digit %= 10;
            int next_num = ten_digit * 10 + num_digit;
            answer++;
            st_num = next_num;
            if(next_num == n)
                break;
        }
        System.out.println(answer);
    }
}