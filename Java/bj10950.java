import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class bj10950 {
  public static void main(String args[]) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String s = bf.readLine();
    int t = Integer.parseInt(s);
    for (int i = 1; i <= t; i++) {
      String str = bf.readLine();
      String input[] = str.split(" ");
      bw.write("Case #" + i + ": " + (Integer.parseInt(input[0]) + Integer.parseInt(input[1])) + "\n");
    }
    bw.flush();
    bw.close();
    bf.close();
  }
}