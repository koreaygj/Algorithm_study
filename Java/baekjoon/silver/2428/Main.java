import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int solution[] = new int[n];
    for (int i = 0; i < n; i++) {
      solution[i] = sc.nextInt();
    }
    Arrays.sort(solution);
    long ans = 0;
    for (int i = 1; i < n; i++) {
      ans += cntIndex(solution, i);
    }
    System.out.println(ans);
    sc.close();
  }

  static int cntIndex(int[] solution, int targetIndex) {
    int leftIndex = 0;
    int rightIndex = targetIndex - 1;
    double target = solution[targetIndex] * 0.9;
    while (leftIndex <= rightIndex) {
      int midIndex = (rightIndex + leftIndex) / 2;
      if (solution[midIndex] < target)
        leftIndex = midIndex + 1;
      else
        rightIndex = midIndex - 1;
    }
    return targetIndex - leftIndex;
  }
}
