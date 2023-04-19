
var maxValue : Int = 0
var maxY : Int = 0
var maxX : Int = 0

fun insertAndInit() {
    repeat(9){
        readln().split(" ").map { it.toInt() }.forEachIndexed { index, value ->
            if (maxValue < value){
                maxValue = value
                maxY = it
                maxX = index
            }
        }
    }
}

fun calculate() {
    println(maxValue)
    print("${maxY+1} ${maxX+1}")
}

fun main() = with(System.`in`.bufferedReader()) {

    insertAndInit()

    calculate()
}