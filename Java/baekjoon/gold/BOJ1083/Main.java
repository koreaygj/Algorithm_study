package Java.baekjoon.gold.BOJ1083;

import java.util.*;

public class Main {

  public static List<Integer> solution(int n, List<Integer> arr, int s){
    for(int i = 0; i < n; i++){
      if(s == 0)
        break;
      int max = 0;
      int maxIndex = -1;
      for(int j = i + 1; j < n; j++){
        if(arr.get(i) < arr.get(j) && s >= j - i){
          if(arr.get(j) > max){
            max = arr.get(j);
            maxIndex = j;
          }
        }
      }
      if(maxIndex != -1){
        arr.remove(maxIndex);
        arr.add(i, max);
        s -= maxIndex - i;
      }
    for(int k : arr){
      System.out.print(k + " ");
    }
    System.out.println();
    }
    return arr;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    List<Integer> v = new ArrayList<>();
    for(int i = 0; i < n; i++){
      v.add(sc.nextInt());
    }
    int s = sc.nextInt();
    sc.close();

    List<Integer> ans = solution(n, v, s);
    for(int i : ans){
      System.out.print(i + " ");
    }
    System.out.println();
  }
}
