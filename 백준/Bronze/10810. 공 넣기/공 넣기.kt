fun main() = with(System.`in`.bufferedReader()) {

    val basket = IntArray(101)

    val (N, M) = readLine().split(" ").map { it.toInt() }

    repeat(M) {
        val (i, j, k) = readLine().split(" ").map { it.toInt() }
        for (current in i..j){
            basket[current] = k
        }
    }

    repeat(N){
        print("${basket[it + 1]} ")
    }
}