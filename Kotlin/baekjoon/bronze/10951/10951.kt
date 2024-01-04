import java.io.*
import java.util.StringTokenizer

fun main() {

  val br = BufferedReader(InputStreamReader(System.`in`))

  try {

    while (true) {
      val line = br.readLine()
      if (line == null) {
        break
      } else {
        val st = StringTokenizer(line)
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        println("${a+b}")
      }
    }
    br.close()

  } catch (e: java.lang.Exception) {
      e.printStackTrace()
  }
}