var K = 0
var score = IntArray(51)

fun insertAndInit() {
    K = readln().toInt()
}

fun calculate() {

    repeat(K){
        var maxNum = 0
        var minNum = 0
        var largestGap = 0
        score = readln().split(" ").map { it.toInt() }.toIntArray().drop(1).toIntArray().sortedArray()
        maxNum = score.last()
        minNum = score.first()
        var lastValue = score[0]
        for (i in 1 until score.size){
            if (score[i] - lastValue > largestGap){
                largestGap = score[i] - lastValue
            }
            lastValue = score[i]
        }
        println("Class ${it+1}")
        println("Max $maxNum, Min $minNum, Largest gap $largestGap")
    }
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}