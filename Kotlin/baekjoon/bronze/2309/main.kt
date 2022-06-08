import java.io.BufferedReader
import java.io.InputStreamReader

val list: MutableList<Int> = mutableListOf()
val check: BooleanArray = BooleanArray(9)
val result: MutableList<Int> = mutableListOf()
var total: Int = 0
var count: Int = 0

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    repeat(9) {
        list.add(readLine().toInt())
    }

    list.sort()

    for (i in list.indices) {
        check[i] = true
        dfs(i, 0, list[i])
        if (result.size == 7) break
        else check[i] = false
    }

    result.forEach { println(it) }
}

fun dfs(start: Int, depth: Int, sum: Int) {
    if (sum >= 100 || depth >= 6) {
        if (sum == 100 && depth == 6) {
            total = sum
            count = depth
            for (i in check.indices)
                if (check[i])
                    result.add(list[i])
            return
        }
        else return
    }

    for (i in start + 1 until 9) {
        if (count == 6 || total == 100) break
        else if (depth <= 6 && sum + list[i] <= 100) {
            check[i] = true
            dfs(i, depth + 1, sum + list[i])
            check[i] = false
        }
    }
}