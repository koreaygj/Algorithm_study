import java.util.*;
public class bj3052{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[42];
        for(int i = 0;i < 10; i++)
        {
            int a = sc.nextInt();
            arr[a % 42]++;
        }
        int answer = 0;
        for(int i = 0;i < 42; i++)
        {
            if(arr[i] != 0)
                answer++;
        }
        System.out.println(answer);
        sc.close();
    }
}