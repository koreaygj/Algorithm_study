import java.util.*;
public class bj5622{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        String[] dial = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
        int answer = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < word.length(); j++)
            {
                if(dial[i].indexOf(word.charAt(j)) != -1)
                    answer += i + 3;
            }
        }
        System.out.println(answer);
        sc.close();
    }
}