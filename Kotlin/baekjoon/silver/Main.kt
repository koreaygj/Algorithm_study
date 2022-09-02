import java.util.*
fun main()
{
    val sc = Scanner(System.`in`)
    val k = sc.nextInt()
    val count = mutableListOf(0, 0, 0, 0, 0)
    val x = Vector<Int>()
    val y = Vector<Int>()
    val list = Vector<Pair<Int, Int>> ()
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
        if(count[list[i].first] == 2)
        {
            if(list[i].first == 1 || list[i].first == 2)
                x.add(list[i].second)
            if(list[i].first == 3 || list[i].first == 4)
                y.add(list[i].second)
        }
    }
    val ans = x[0] * y[0] + x[1] * y[1] + x[1] * y[0]
    println(ans * k)
}