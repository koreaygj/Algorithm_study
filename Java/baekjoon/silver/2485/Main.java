import java.util.*;
public class Main{
    public static int gcp(int a, int b){
        int c;
        while(a != 0){
            c = b % a;
            b = a;
            a = c;
        }
        return b;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> tree = new ArrayList<>();
        for(int i = 0; i < n; i++){
            arr.add(sc.nextInt());
        }
        arr.sort(Comparator.naturalOrder());
        int road = arr.get(n - 1) - arr.get(0);
        for(int i = 0; i < n - 1; i++){
            tree.add(arr.get(i + 1) - arr.get(i));
        }
        int gap = tree.get(0);
        for(int i = 1; i < n - 1; i++){
            gap = gcp(gap, tree.get(i));
        }
        
        System.out.println(road/gap + 1 - n);
        sc.close();
    }
}