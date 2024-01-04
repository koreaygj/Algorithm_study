package Java.programmers.LV3.하노이탑;
import java.util.*;


public class Main {
    static int[][] answer;
    static int cnt = 0;
    static void hanoi(int n, int st, int mid, int end){
        if(n == 1){
            answer[cnt][0] = st;
            answer[cnt][1] = end;
            cnt++;
            return;
        }
        hanoi(n - 1, st, mid, end);
        answer[cnt][0] = st;
        answer[cnt][1] = end;
        cnt++;
        hanoi(n - 1, mid, st, end);
    }
    static int[][] solution(int n){
        answer = new int[(int)(Math.pow(2, n) - 1)][2];
        hanoi(n, 1, 2, 3);
        return answer;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        solution(n);
    }    
}
