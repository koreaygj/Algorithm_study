import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int left = 0, right = -1;
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
            right = Math.max(right, arr[i]);
        }
        int m = sc.nextInt();
        sc.close();
		while(left<=right) {
			int mid = (left + right)/2;
			long budget =0;
			for(int i=0; i < n; i++) {
				if(arr[i] > mid) budget += mid;
				else budget+= arr[i];
			}
			if(budget <= m) {
				left = mid + 1;
			}else {
				right = mid - 1;
			}
		}
        System.out.println(right);
    }
}
