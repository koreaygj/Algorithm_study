import java.util.*;
public class bj10809{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] alphabet = new int[26];
        Arrays.fill(alphabet, -1);
        for(int i = 0; i < s.length(); i++)
        {
            if(alphabet[s.charAt(i)-'a'] < i && alphabet[s.charAt(i)-'a'] != -1)
                continue;
            alphabet[s.charAt(i) - 'a'] = i;
        }
        for(int i = 0; i < 26 ; i++)
            System.out.print(alphabet[i] + " ");
    }
}