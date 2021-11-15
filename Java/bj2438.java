import java.util.*;

public class bj2438 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String a = "*";
    String b = " ";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - i; j++)
        System.out.print(b);
      for (int j = 1; j <= i; j++)
        System.out.print(a);
      System.out.print("\n");
    }
    sc.close();
  }
}
