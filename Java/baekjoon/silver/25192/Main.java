import java.util.*;

public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n;
    n = sc.nextInt();
    sc.nextLine();
    int ans = 0;
    HashMap<String, Integer> check = new HashMap<>();
    for(int i = 0; i < n; i++){
      String s = sc.nextLine();
      if(s.equals("ENTER")){
        check = new HashMap<>();
        continue;
      }
      if(check.containsKey(s))
        continue;
      check.put(s, 1);
      ans++;
    }
    System.out.println(ans);
    sc.close();
  }
}