import java.util.*;

public class bj2738 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= 9; i++) {
      System.out.println(n + " * " + i + " = " + n * i);
    }
    sc.close();
  }
}
