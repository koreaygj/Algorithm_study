package Java.programmers.LV1.slice;
import java.util.*;

public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String input = sc.nextLine();
    int same = 1;
    int another = 0;
    char check = input.charAt(0);
    int answer = 0;
    for(int i = 1; i < input.length(); i++){
      if(same == another){
        answer++;
        check = input.charAt(i);
        same = 0;
        another = 0;
      }
      if(check == input.charAt(i))
        same++;
      else
        another++;
      }
      answer++;
      System.out.println(answer);
  }
}