val numList = IntArray(5)

fun insertAndInit() {
    repeat(5){
        numList[it] = readln().toInt()
    }
    numList.sort()
}

fun calculate() {

    // 평균 구하기
    println(numList.average().toInt())

    // 중앙값 구하기
    print(numList[numList.size / 2])
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}