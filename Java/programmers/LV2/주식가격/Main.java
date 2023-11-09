package Java.programmers.LV2.주식가격;
import java.util.*;

public class Main {
  public int[] solution(int[] prices) {
    int[] answer = new int[prices.length];
    for (int i = 0; i < prices.length; i++) {
        for (int j = i + 1; j < prices.length; j++) {
            answer[i]++;
            if (prices[i] > prices[j])
                break;
        }
    }
    return answer;
  }
}
