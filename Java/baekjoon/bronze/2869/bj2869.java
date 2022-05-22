import java.util.*;
import java.io.*;
public class bj2869{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        br.close();
        String input[] = str.split(" ");
        long a = Long.parseLong(input[0]);
        long b = Long.parseLong(input[1]);
        long v = Long.parseLong(input[2]);
        if(a >= v)
        {
            System.out.println(1);
            return;
        }
        v -= a;
        a -= b;
        long answer = v / a;
        if(v % a != 0)
            answer += 2;
        else
            answer += 1;
        System.out.println(answer);
    }
}