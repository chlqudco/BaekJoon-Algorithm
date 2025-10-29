class Solution {
    fun solution(numbers: IntArray): String {
    val arr = numbers.map { it.toString() }
        .sortedWith { a, b -> (b + a).compareTo(a + b) }  // 내림차순 정렬 기준

    val answer = arr.joinToString("")
    return if (answer[0] == '0') "0" else answer
    }
}