import java.util.Stack

var K = 0
val money = Stack<Int>()

fun insertAndInit() {
    K = readln().toInt()
}

fun calculate() {

    repeat(K){
        val currentInput = readln().toInt()

        // 0인 경우
        if (currentInput == 0){
            money.pop()
        }
        else{
            money.push(currentInput)
        }
    }

    // 총 합 계산
    var total = 0
    while (!money.empty()){
        total += money.pop()
    }

    print(total)

}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}