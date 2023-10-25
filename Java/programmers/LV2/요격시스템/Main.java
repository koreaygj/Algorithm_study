package Java.programmers.LV2.요격시스템;
import java.util.*;

public class Main {
  public void main(String args[]){
  public int solution(int[][] target){
    int answer = 0;
    Arrays.sort(target, (e1, e2) -> {
      return e1[1] - e2[1];
    });
    for(int i = 0; i < target.length; i++){
      for(int j = 1; j < target.length; j++){
        if(target[i][0] > target[j][0]){
          answer++;

          break;
        }
      }
      System.out.println(target[i][0]+ "  " +target[i][1]);
    }
    return answer;
  }
}

