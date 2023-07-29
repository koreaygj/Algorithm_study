import java.util.*;
public class Main{
    static boolean isdecimal(long num){
        if(num == 1)
            return false;
        for(int i = 2; i * i < num; i++)
            if(num % i == 0)
                return false;
        return true;
    }
    static String[] makebitnum(int n, int k){
        StringBuilder tmp = new StringBuilder();
        while(n != 0){
            tmp.insert(0, n % k);
            n /= k;    
        }
        String[] result = tmp.toString().split("0");
        return result;
    }
    public static int solution(int n, int k){
        int answer = 0;
        String[] num = makebitnum(n, k);
        for(int i = 0; i < num.length; i++){
            if(num[i].equals(""))
                continue;
            if(isdecimal(Long.parseLong(num[i])))
                answer++;
        }
        return answer;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(solution(n, k));
        sc.close();
    }
}