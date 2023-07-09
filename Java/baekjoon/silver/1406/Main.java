import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class Main{
    static class Editor{
        String text;
        Stack<Character> left = new Stack<Character>();
        Stack<Character> right = new Stack<Character>();
        void print()throws IOException{
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            while(!left.empty())
                right.push(left.pop());
            while(!right.empty())
                bw.write(right.pop());
            bw.close();
        }
        public void input() throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            text = br.readLine();
            for(int i = 0; i < text.length();i++)
                left.push(text.charAt(i));
            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++){
                String commend = br.readLine();
                if(commend.length() == 0)
                    continue;
                if(commend.charAt(0) == 'L'){
                    if(left.empty())
                        break;
                    right.push(left.pop());
                }
                if(commend.charAt(0) == 'D'){
                    if(right.empty())
                        break;
                    left.push(right.pop());
                }
                if(commend.charAt(0) == 'B'){
                    if(left.empty())
                        break;
                    left.pop();
                }
                if(commend.charAt(0) == 'P'){
                    left.push(commend.charAt(2));
                }
            }   
            br.close();
            print();
        }
    }
    public static void main(String args[])throws IOException{
        Editor e = new Editor();
        e.input();
    }
}