fun main() {
    val lines = Array(3) { readln().split(" ").map { it.toInt() }.toPair() }

    val x = lines.map { it.first }.groupingBy { it }.eachCount().filter { it.value == 1 }.keys.first()
    val y = lines.map { it.second }.groupingBy { it }.eachCount().filter { it.value == 1 }.keys.first()

    println("$x $y")
}

fun <T> List<T>.toPair(): Pair<T, T> = Pair(this[0], this[1])