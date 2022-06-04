import java.io.*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val arr = ArrayList<Int>()
    for (i in 1..N) {
        val num = br.readLine().toInt()
        arr.add(num)
    }
    arr.sort()
    for (k in arr) {
        println(k)
    }
    br.close()
}