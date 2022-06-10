import java.util.*;
import java.io.*;
import kotlin.math.*;
fun main(){
    val sc:Scanner = Scanner(System.`in`)
    val x:Int = sc.nextInt()
    val y:Int = sc.nextInt()
    val w:Int = sc.nextInt()
    val h:Int = sc.nextInt()
    println(min(min(w - x, h - y), min(x - 0, y - 0)))
}