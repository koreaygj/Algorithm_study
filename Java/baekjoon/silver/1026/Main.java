import java.util.*;
public class Main{
    public static boolean comp(Integer a, Integer b){
        return a > b;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> A = new ArrayList<Integer>();
        ArrayList<Integer> B = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
            A.add(sc.nextInt());
        for(int i = 0; i < n; i++)
            B.add(sc.nextInt());
        A.sort(Comparator.naturalOrder());
        B.sort(Comparator.reverseOrder());
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += A.get(i) * B.get(i);
        System.out.println(ans);
        sc.close();

    }
}