fun main() = with(System.`in`.bufferedReader()) {
    val n = readln().toInt()
    val v = List(n) {
        val input = readln().toInt()
        Pair(input, it)
    }.sortedBy { it.first }

    var ans = -1
    for (i in v.indices) {
        ans = maxOf(ans, v[i].second - i)
    }

    println(ans + 1)
}