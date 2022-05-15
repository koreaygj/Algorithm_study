import java.util.*;
public class bj1546{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        double is_max = 0;
        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextDouble();
            if(is_max < arr[i])
                is_max = arr[i];
        }
        double avg = 0;
        for(int i = 0; i < n; i++)
        {
            avg += arr[i] / is_max * 100;
        }
        System.out.println(avg/n);
    }
}