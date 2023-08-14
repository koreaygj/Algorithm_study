import java.util.*;

public class Main {
    static int solution(String s, String t){
        int answer = 0;
        while(s.length() <= t.length()){
            if(s.length() == t.length())
                return s.equals(t) ? 1 : 0;
            if(t.charAt(t.length() - 1) == 'B'){
                StringBuilder sb = new StringBuilder(t.substring(0, t.length() - 1));
                t = sb.reverse().toString();
            }
            else if(t.charAt(t.length() - 1) == 'A'){
                t = t.substring(0, t.length() - 1);
            }
        }
        return answer;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        System.out.println(solution(s, t));
        sc.close();
    }
}
