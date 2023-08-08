import java.util.*;

public class Main{
  static boolean solution(String s) {
    boolean answer = true;
    Stack<String> st = new Stack<>();
    int cnt = 0;
    while (cnt < s.length()) {
      if (s.charAt(cnt) == '(') {
        st.push("(");
      } else {
        if (st.empty()) {
          return answer = false;
        } else {
          if (st.peek() == "(")
            st.pop();
          else
            return answer = true;
        }
      }
      cnt++;
    }
    if(st.empty())
      return answer;
    else
      return answer = false;
  }
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    sc.close();
    System.out.println(solution(s));
  }
}