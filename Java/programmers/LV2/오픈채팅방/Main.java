package Java.programmers.LV2.오픈채팅방;

import java.util.*;
public class Main {
  public static String[] solution(String[] record) {
    HashMap<String, String> users = new HashMap<>();
    String[][] str = new String[record.length][];
    int cnt = record.length;
    for (int i = 0; i < record.length; i++) {
      str[i] = record[i].split(" ");
      if(str[i][0].equals("Enter"))
        users.put(str[i][1], str[i][2]);
      else if(str[i][0].equals("Change")){
        users.put(str[i][1], str[i][2]);
        cnt--;        
      }
    }
    String[] answer = new String[cnt];
    cnt = 0;
    for (int i = 0; i < record.length; i++) {
      if(str[i][0].equals("Enter")){
        answer[cnt] = users.get(str[i][1]) + "님이 들어왔습니다.";
        cnt++;        
      }
      else if (str[i][0].equals("Leave")) {
        answer[cnt] = users.get(str[i][1]) + "님이 나갔습니다.";
        cnt++;        
      }
  
    }
    return answer;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String[] record = new String[n];
    sc.nextLine();
    for(int i = 0; i < n; i++)
      record[i] = sc.nextLine();
    sc.close();
    record = solution(record);
    for(int i = 0; i < n - 1; i++)
      System.out.println(record[i]);
    return;
  }
}
