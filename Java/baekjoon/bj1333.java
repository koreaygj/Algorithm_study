import java.util.*;

public class bj1333 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt();
    int b = scan.nextInt();
    scan.close();
    if (a > b)
      System.out.println(">");
    else if (a < b)
      System.out.println("<");
    else
      System.out.println("==");
  }
}