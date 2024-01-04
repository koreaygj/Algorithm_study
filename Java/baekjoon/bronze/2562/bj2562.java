import java.util.*;

public class bj2562{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[9];
        int is_max = 0;
        int max_index = 0;
        for(int i = 0; i < 9; i++)
        {
            arr[i] = sc.nextInt();
            if(arr[i] > is_max)
            {
                is_max = arr[i];
                max_index = i+1;
            }
        }
        System.out.println(is_max);
        System.out.println(max_index);
        sc.close();
    }
}