import java.util.*;

public class bj10818{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int isMax = -1000001, isMin = 1000001;
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
            if(isMax < arr[i])
                isMax = arr[i];
            if(isMin > arr[i])
                isMin = arr[i];
        }
        System.out.println(isMin + " " + isMax);
    }
}