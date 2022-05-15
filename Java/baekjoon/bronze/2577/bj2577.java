import java.util.*;
public class bj2577{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int total = a * b * c;
        int[] arr = new int[10];
        while(total != 0)
        {
            arr[total % 10]++;
            total /= 10;
        }
        for(int i = 0;i < 10; i++)
            System.out.println(arr[i]);
    }
}