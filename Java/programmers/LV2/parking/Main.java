 import java.util.*;

 public class Main {
   public static int Cal(String a, String b) {
     int result = 0;
     String[] s_a = a.split(":");
     String[] s_b = b.split(":");
     int[] i_a = new int[2];
     int[] i_b = new int[2];
     i_a[0] = Integer.parseInt(s_a[0]);
     i_a[1] = Integer.parseInt(s_a[1]);
     i_b[0] = Integer.parseInt(s_b[0]);
     i_b[1] = Integer.parseInt(s_b[1]);
     result += (i_b[0] - i_a[0]) * 60 + (i_b[1] - i_a[1]);
     return result;
   }

   public static int Cost(int time, int[] fees) {
    if(time < fees[0])
      return fees[1];
    time -= fees[0];
    return fees[1] + (int) Math.ceil((double) time / (double) fees[2]) * fees[3];
   }
   public static int[] solution(int[] fees, String[] records) {
     HashMap<Integer, Integer> cars = new HashMap<>();
     String[][] time = new String[10000][2];
     for (int i = 0; i < records.length; i++) {
       String[] str = records[i].split(" ");
       int index = Integer.parseInt(str[1]);
       if (str[2].equals("IN")) {
         time[index][0] = str[0];
         time[index][1] = null;
         if(!cars.containsKey(index))
          cars.put(index, 0);
       } else {
         time[index][1] = str[0];
         int cost = Cal(time[index][0], time[index][1]);
          cars.put(index, cars.get(index) + cost);
       }
     }
     int[] answer = new int[cars.size()];
     int cnt = 0;
     for (int i = 0; i < 10000; i++) {
       if (time[i][0] != null) {
         if (time[i][1] == null) {
           int cost = Cal(time[i][0], "23:59");
             cars.put(i, cars.get(i) + cost);
         }
         answer[cnt++] = Cost(cars.get(i), fees);
      }
     }
     return answer;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int[] fees = new int[4];
    for (int i = 0; i < 4; i++)
      fees[i] = sc.nextInt();
    int n = sc.nextInt();
    sc.nextLine();
    String[] records = new String[n];
    for (int i = 0; i < n; i++)
      records[i] = sc.nextLine();
    solution(fees, records);
    sc.close();
  }
}
