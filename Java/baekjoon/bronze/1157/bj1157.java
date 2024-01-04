import java.util.*;
public class bj1157{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        sc.close();
        int alphabet[] = new int[26];
        Arrays.fill(alphabet, 0);
        int max = 0;
        int max_index = 65;
        int check = 0;
        for(int i = 0; i < input.length() ; i++)
        {
            if(input.charAt(i) <= 'z' && input.charAt(i) >= 'a'){
                alphabet[input.charAt(i) - 'a']++;;
            }
            else if(input.charAt(i) <= 'Z' && input.charAt(i) >= 'A')
                alphabet[input.charAt(i) - 'A']++;
        }
        for(int i = 0;i < 26; i++)
        {
            if(alphabet[i] > max)
            {
                max = alphabet[i];
                max_index = 65 + i;
            }
        }
        for(int i = 0; i< 26; i++)
        {
            if(alphabet[i] == max)
                check++;
        }
        if(check == 1){
            System.out.println(Character.toString(max_index));
        }
        else System.out.println("?");
    }
}