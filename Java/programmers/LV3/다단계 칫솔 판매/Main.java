package Java.programmers.LV3.다단계 칫솔 판매;
import java.util.*;

public class Main {
  public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
    int[] answer = new int[enroll.length];
    Map<String, String> trunk = new HashMap<>();
    Map<String,Integer> income = new HashMap<>();
    for(int i = 0; i < enroll.length; i++){
        if(enroll != null){
          trunk.put(enroll[i], referral[i]);
          income.put(enroll[i], 0);
        }
    }
    for(int i = 0; i < amount.length; i++){
        int total = amount[i] * 100;
        int parentIncome = total / 10;
        int childIncome = total - parentIncome;
        String name = seller[i];
        if(trunk.containsKey(name)){
          income.put(name, income.get(name) + childIncome);
          while(!trunk.get(name).equals("-")){
            name = trunk.get(name);
            if(total == 0)
              break;
            else
              total /= 10;
            parentIncome = total / 10;
            childIncome =  total - parentIncome;
            income.put(name, income.get(name) + childIncome);
          }
        }
      }
      int index = 0;
      for(String name : enroll){
        answer[index++] = income.get(name);
      }
    return answer;
  }
}
