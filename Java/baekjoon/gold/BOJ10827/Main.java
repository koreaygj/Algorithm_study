package Java.baekjoon.gold.BOJ10827;

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    br.close();
    BigDecimal a = new BigDecimal(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    System.out.println(a.pow(b).toPlainString());
  }
}