import kotlin.math.*

var N = 0
var arr = IntArray(100001)

fun insertAndInit() {
    N = readln().toInt()
    arr = readln().split(" ").map { it.toInt() }.toIntArray()

    arr.sort()
}

fun calculate() {
    var answer = arr[N-1] + arr[0]
    var start = 0
    var end = N-1
    var a1 = arr[0]
    var a2 = arr[N - 1]
    while(start < end){
        // 현재 용액 계산하기
        val current = arr[end] + arr[start]

        // 최선의 답 인 경우
        if(abs(answer) > abs(current)){
            answer = current
            a1 = arr[end]
            a2 = arr[start]
        }

        if (current < 0){
            start += 1
        } else {
            end -= 1
        }
    }
    if (a1 > a2){
        print("$a2  $a1")
    } else {
        print("$a1  $a2")
    }


}

fun main() = with(System.`in`.bufferedReader()) {
    insertAndInit()

    calculate()
}