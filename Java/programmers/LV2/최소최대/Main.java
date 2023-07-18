import java.util.*;
public class Main {
  public static String solution(String s) {
    String answer = "";
    String[] arr = s.split(" ");
    int left = Integer.parseInt(arr[0]);
    int right = left;
    for (int i = 1; i < arr.length; i++) {
      int next = Integer.parseInt(arr[i]);
      left = Math.min(left, next);
      right = Math.max(right, next);
    }
    answer = Integer.toString(left) + " " + Integer.toString(right);
    return answer;
  }
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);    
    String s = sc.nextLine();
    System.out.println(solution(s));
    sc.close();
  }
}