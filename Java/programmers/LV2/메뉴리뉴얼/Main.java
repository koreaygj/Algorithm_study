package Java.programmers.LV2.메뉴리뉴얼;

import java.util.*;

public class Main {
  static HashMap<String, Integer> menu;

  public static void dfs(int st, String order, String tmp, int course) {
    if (tmp.length() == course) {
      char[] chars = tmp.toCharArray();
      Arrays.sort(chars);
      tmp = new String(chars);
      if (menu.containsKey(tmp))
        menu.put(tmp, menu.get(tmp) + 1);
      else
        menu.put(tmp, 1);
      return;
    }
    if (st + 1 > order.length())
      return;
    dfs(st + 1, order, tmp, course);
    dfs(st + 1, order, tmp + order.charAt(st), course);
    return;
  }

  public static String[] solution(String[] orders, int[] course) {
    List<String> list = new ArrayList<>();
    for (int i = 0; i < course.length; i++) {
      menu = new HashMap<>();
      for (int j = 0; j < orders.length; j++) {
        dfs(0, orders[j], "", course[i]);
      }
      if(menu.isEmpty())
        break;
      int max = Collections.max(menu.values());
      if(max == 1)
        continue;
      List<String> keyset = new ArrayList<>(menu.keySet());
      for (String str : keyset) {
        if (max == menu.get(str)) {
          list.add(str);
        }
      }
    }
    Collections.sort(list);
    return list.toArray(new String[0]);
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String[] str = new String[n];
    sc.nextLine();
    for (int i = 0; i < n; i++) {
      str[i] = sc.nextLine();
    }
    String s = sc.nextLine();
    String[] tmp = (s.split(","));
    int[] course = new int[tmp.length];
    for(int i = 0; i < tmp.length; i++)
      course[i] = Integer.parseInt(tmp[i]);
    sc.close();
    String[] ans = solution(str, course);
    for(int i = 0; i < ans.length; i++)
      System.out.println(ans[i]);
  }
}
