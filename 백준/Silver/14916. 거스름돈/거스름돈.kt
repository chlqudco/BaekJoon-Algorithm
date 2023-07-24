
var n = 0

fun insertAndInit() {
    n = readln().toInt()
}

fun calculate() {
    var answer = 0

    while(n > 0){
        if (n % 5 == 0){
            answer += n/5
            n = 0
        } else {
            n -= 2
            answer++
        }
    }
    if (n == 0) {
        print(answer)
    } else {
        print("-1")
    }

}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}