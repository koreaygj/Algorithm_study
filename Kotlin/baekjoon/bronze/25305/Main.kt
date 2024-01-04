import java.util.*
fun main()
{
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val k = sc.nextInt()
    sc.nextLine()
    var list = Vector<Int>()
    for(i in 1..n)
    {
        val a = sc.nextInt()
        list.add(a)
    }
    list.sort()
    list.reverse()
    println("sorted : $list")
    println(list[k - 1])
}