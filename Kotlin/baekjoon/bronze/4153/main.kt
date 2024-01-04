import java.util.*
import java.io.*
fun main(){
    while(true)
    {
        val a = Array{ readln().split(" ").map { it.toInt() }}
        if(a[0] == 0 && a[1] == 0 && a[2] == 0)
            break;
        val sorted = a.sorted()
        if(sorted[2] * sorted[2] == sorted[0] * sorted[1])
            println("right")
        else
            println("wrong")
    }
}