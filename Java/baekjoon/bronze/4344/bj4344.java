import java.util.*;
public class bj4344{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        for(int i = 0; i < c ; i++)
        {
            int n = sc.nextInt();
            int[] student = new int[n];
            int avg = 0;
            double answer = 0;
            for(int j = 0; j < n ;j++)
            {
                student[j] = sc.nextInt();
                avg += student[j];
            }
            avg /= n;
            for(int j = 0; j < n; j++)
            {
                if(avg < student[j])
                    answer++;
            }
            answer = answer / n * 100;
            answer *= 1000;
            answer = Math.round(answer);
            System.out.println(String.format("%.3f", answer/1000) + "%");
        }
        sc.close();
    }
}