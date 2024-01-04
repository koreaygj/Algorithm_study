package Java.programmers.LV2.호텔대실;
import java.util.*;

public class Main {

  public int solution(String[][] book_time){
    int[][] bookTimeNum = new int[book_time.length][2];
    for(int i = 0; i < book_time.length; i++){
      int startTime = Integer.parseInt(book_time[i][0].replace(":", ""));
      int endTime = Integer.parseInt(book_time[i][1].replace(":", ""));
      endTime += 10;
      if(endTime % 100 >= 60){
        endTime += 40;
      }
      bookTimeNum[i][0] = startTime;
      bookTimeNum[i][1] = endTime;
    }

    Arrays.sort(bookTimeNum, (a, b) -> {
      if(a[0] == b[0])
        return a[1] - b[1];
      return a[0] - b[0];
    });

    PriorityQueue<Integer> rooms = new PriorityQueue<>();


    for(int[] curBook : bookTimeNum){
      if(rooms.size() == 0){
        rooms.add(curBook[1]);
        continue;
      }
      int emptyRoom = rooms.peek();
      if(curBook[0] >= emptyRoom){
        rooms.poll();
        rooms.add(curBook[1]);
      }
      else{
        rooms.add(curBook[1]);
      }
    }

    return rooms.size();
  }

  public static void main(String args[]){

  }
}
