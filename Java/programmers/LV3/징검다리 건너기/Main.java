import java.util.*;

public class Main {
  public boolean checkPass(int[] stones, int k, int person){
    int cnt = 0;
    for(int i = 0; i < stones.length; i++){
      if(stones[i] - person <= 0)
        cnt++;
      else
        cnt = 0;
      if(cnt >= k)
        return false;
    }
    return true;
  }
  public int solution(int[] stones, int k) {
    int answer = 0;
    int minNum = 0;
    int maxNum = 0;
    for(int i = 0; i < stones.length; i++){
      maxNum = Math.max(maxNum, stones[i]);
    }  
    int midNum = 0;
    while(minNum <= maxNum){
      midNum = (minNum + maxNum) / 2;
      if(checkPass(stones, k, midNum)){
        minNum = midNum + 1;
      }else{
        maxNum = midNum - 1;
      }
    }
    answer = minNum;
    return answer;
  }
}
