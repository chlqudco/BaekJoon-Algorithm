var dp = IntArray(11)

fun insertAndInit() {
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    for (i in 4..10){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    }
}

fun calculate() {
    var T = 0
    T = readln().toInt()

    repeat(T){
        println("${dp[readln().toInt()]}")
    }
    
}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}