class test {
  public static void main(String[] args) {
    ThreadTest t = new ThreadTest();
    t.start();
  }
}

class ThreadTest extends Thread {
  public void run() {
    try {
      for (int i = 0; i < 10; i++) {
        Thread.sleep(200);
        System.out.println("정용훈");
      }
    } catch (Exception e) {
      // TODO: handle exception
      System.out.println(e);
    }
  }
}