import java.util.*

fun check(tChar: IntArray, selectedChar: IntArray): Boolean {
    for (i in 0..25) {
        if (tChar[i] > selectedChar[i]) {
            return false
        }
    }
    return true
}

fun combination(cnt: Int, priceSum: Int, n: Int, book: Array<Pair<Int, String>>, tChar: IntArray, selectedChar: IntArray): Int {
    if (cnt == n) {
        if (check(tChar, selectedChar)) {
            return priceSum
        }
        return 987654321
    }
    for (i in book[cnt].second.indices) {
        selectedChar[book[cnt].second[i] - 'A']++
    }
    val use = combination(cnt + 1, priceSum + book[cnt].first, n, book, tChar, selectedChar)
    for (i in book[cnt].second.indices) {
        selectedChar[book[cnt].second[i] - 'A']--
    }
    val skip = combination(cnt + 1, priceSum, n, book, tChar, selectedChar)
    return minOf(use, skip)
}

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.next()
    val n = scanner.nextInt()

    val tChar = IntArray(26)
    for (i in t.indices) {
        tChar[t[i] - 'A']++
    }

    val book = Array(n) {
        Pair(scanner.nextInt(), scanner.next())
    }

    val selectedChar = IntArray(26)
    val result = combination(0, 0, n, book, tChar, selectedChar)

    if (result == 987654321) {
        println(-1)
    } else {
        println(result)
    }
}