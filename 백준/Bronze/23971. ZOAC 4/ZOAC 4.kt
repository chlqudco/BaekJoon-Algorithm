var H = 0
var W = 0
var N = 0
var M = 0

fun insertAndInit() {
    val input = readln().split(" ").map { it.toInt() }
    H = input[0]
    W = input[1]
    N = input[2]
    M = input[3]
}

fun calculate() {
    var answer = 0
    if(H % (N+1) != 0){
        answer += (H / (N+1) + 1)
    } else {
        answer += (H / (N+1))
    }

    if(W % (M+1) != 0){
        answer *= ((W / (M+1)) + 1)
    } else {
        answer *= (W / (M+1))
    }

    print(answer)
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}