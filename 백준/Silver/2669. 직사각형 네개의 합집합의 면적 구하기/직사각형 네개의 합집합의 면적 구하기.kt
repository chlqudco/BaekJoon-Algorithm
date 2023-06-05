var map = Array(101) { BooleanArray(101) { false } }

fun insertAndInit() {
    repeat(4){
        val input = readln().split(" ").map { it.toInt() }
        for (i in input[0] until input[2]){
            for (j in input[1] until input[3]){
                map[i][j] = true
            }
        }
    }
}

fun calculate() {
    var answer = 0

    for (i in 0 .. 100){
        for (j in 0..100){
            if (map[i][j]) answer++
        }
    }

    print(answer)
}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}