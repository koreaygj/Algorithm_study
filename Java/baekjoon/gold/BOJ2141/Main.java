package Java.baekjoon.gold.BOJ2141;
import java.util.*;


public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] arr = new int[n][2];
    long totalPerson = 0;
    for(int i = 0; i < n; i++){
      arr[i][0] = sc.nextInt();
      arr[i][1] = sc.nextInt();
      totalPerson += arr[i][1];
    }
    long cntPerson = 0;
    long answer = 0;
    Arrays.sort(arr, (o1, o2) -> o1[0] - o2[0]);
    for(int i = 0; i < n; i++){
      cntPerson += arr[i][1];
      if(cntPerson >= (totalPerson + 1) / 2){
        answer = arr[i][0];
        break;
      }
    }
    System.out.println(answer);
  }
}
