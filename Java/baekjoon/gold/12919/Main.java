import java.util.*;

public class Main {
    static int solution(String s, String t){
        if(t.length() == s.length()){
            return s.equals(t) ? 1 : 0;
        }
        int answer = 0;
        if(t.charAt(0) == 'B'){
            StringBuilder sb = new StringBuilder(t.substring(1));
            String tmp = sb.reverse().toString();
            answer += solution(s, tmp);
        }
        if(t.charAt(t.length() - 1) == 'A'){
            String tmp = t.substring(0, t.length() - 1);
            answer += solution(s, tmp);
        }
        return answer > 0 ? 1 : 0;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        System.out.println(solution(s, t));
        sc.close();
    }
}
