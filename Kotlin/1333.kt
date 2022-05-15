import java.util.*
fun main(){
  val a = readLine()!!.toInt()
  val b = a.split(" ")
  if(b[0] > b[1])
    println(">")
  else if(b[0] > b[1])
    println("<")
  else
    println("==")
}