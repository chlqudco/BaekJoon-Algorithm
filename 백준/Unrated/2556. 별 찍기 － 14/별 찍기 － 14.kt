var N = 0

fun insertAndInit() {
    N = readln().toInt()
}

fun calculate() {
    repeat(N){
        repeat(N){
            print("*")
        }
        println()
    }
}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}