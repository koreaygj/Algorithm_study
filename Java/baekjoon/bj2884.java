import java.util.*;

public class bj2884 {
  public static void main(String arg[]) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int sum = a * 60 + b - 45;
    sc.close();
    if (sum < 0)
      sum = 24 * 60 + b - 45;
    System.out.println(sum / 60 + " " + sum % 60);
  }
}
