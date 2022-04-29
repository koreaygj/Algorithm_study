import java.util.*
import java.util.Scanner
fun main()
{
 val sc: Scanner = Scanner(System.`in`)
 while(true)
 {
  val a:Int = sc.nextInt()
  val b:Int = sc.nextInt()
  if(a == 0 && b == 0) break;
  println(add(a, b))
 }
}
fun add(a: Int, b: Int): Int{
 return a+b
}