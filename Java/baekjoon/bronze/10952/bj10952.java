import java.util.*;

public class bj10952 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int a = 0, b = 0;
    do {
      a = sc.nextInt();
      b = sc.nextInt();
      System.out.println(a + b);
    } while (a != 0 && b != 0);
    sc.close();
  }
}