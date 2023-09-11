
var T = 0

fun insertAndInit() {
    T = readln().toInt()
}

fun calculate() {
    repeat(T){
        val str = readln()

        // 자리수 구하기
        var num = 1
        while( num * num != str.length){
            num++
        }
        for (i in 1 .. num){
            for (j in 1 .. num){
                print("${str[(num*j) - i]}")
            }
        }
        println()
    }
}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}