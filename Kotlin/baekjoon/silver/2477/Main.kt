import java.util.*
import kotlin.math.*
fun main()
{
    val sc = Scanner(System.`in`)
    val k = sc.nextInt()
    val count = mutableListOf(0, 0, 0, 0, 0)
    val x = Vector<Int>()
    val list = Vector<Pair<Int, Int>> ()
    var ans = 1
    sc.nextLine()
    for(i in 1..6)
    {
        val dist = sc.nextInt()
        val length = sc.nextInt()
        sc.nextLine()
        list.add(Pair(dist, length))
        count[dist]++
    }
    for(i in 0..5)
    {
        if(count[list[i].first] == 1)
        {
            ans *= list[i].second
            if(i == 0)
                x.add(abs(list[5].second - list[i + 1].second))
            else if(i == 5)
                x.add(abs(list[0].second - list[i - 1].second))
            else
                x.add(abs(list[i - 1].second - list[i + 1].second))
        }
    }
    ans -= x[0] * x[1]
    println(ans * k)
}